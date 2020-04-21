#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void) {
    FILE *fp;
    fp = fopen("test.wav", "r");
    WAVheader h = readwavhdr(fp);
    clearscreen();
    //displayWAVhdr(h);
    wavdata(h, fp);
    fclose(fp);
    getchar();
}
