#include <stdio.h>
#include <math.h>
#include "sound.h"
#include "screen.h"
#include "comm.h"

WAVheader readwavhdr(FILE *fp) {
    WAVheader myh;
    fread(&myh, sizeof(myh), 1, fp);
    return myh;
}

void displayWAVhdr(WAVheader h) {
    printf("Chunk ID: ");
    for (int i = 0; i < 4; i++) {
        printf("%c", h.chunkID[i]);
    }
    printf("\nChunk size: %d\n", h.chunkSize);
    printf("Num of Channels: %d\n", h.numChannels);
    printf("Sample rate: %d\n", h.sampleRate);
    printf("Block align: %d\n", h.blockAlign);
    printf("Bits per sample: %d\n", h.bitsPerSample);
    // ... to be continued
}

void wavdata(WAVheader h, FILE* fp) {
    // in this function we will read samples from the opened file
    // the samples are calculated in to decibel value using
    // Root Mean Square (RMS) formula. We will display a 5-sec
    // recorded sound into bar chart
    // Our sound file uses sample rate of 16000, for 5 seconds, 
    // there are 5*16000 = 80000 samples, we want to display them
    // into 160 bars
    
    short samples[500]; //to read 500 samples from wav file
    short peaks = 0, flag = 0;
    short max_db_value = 0;

    for (int i = 0; i < 160; i++) {
        fread(samples, sizeof(samples), 1, fp);
        double sum = 0.0;   // accumulate the sum

        for (int j = 0; j < 500; j++) {
            sum = sum + samples[j] * samples[j];
        }

        double re = sqrt(sum/500);
#ifdef SDEBUG
        printf("db[%d] = %f\n", i+1, 20*log10(re));
#else
        // display re value
        double re_value = (int)20* log10(re);
        if (re_value > max_db_value) {
            max_db_value = re_value;
        }

        if (re_value > 60) {
            setfgcolor(RED);
            if (flag == 0) {
                peaks++;
                flag = 1;
            }
        } else {
            setfgcolor(WHITE);
            flag = 0;
        }
        drawbar(i+1, re_value/3);
#endif
    }
    gotoXY(1, 1);
    printf("Sample rate: %d", h.sampleRate);
    gotoXY(1, 70);
    printf("Duration: %.2f s\n", (float)h.subchunk2Size / h.byteRate);
    gotoXY(1, 140);
    printf("Peaks count: %d", peaks);

    char* url = "http://www.cc.puv.fi/~e1900311/php/sound.php";
    char post_data[32];
    sprintf(post_data, "%s%d%s%d", "peaks=", peaks, "&maxDB=", max_db_value);
    senddata(post_data, url);
    getchar();
    clearscreen();
}
