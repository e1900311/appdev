#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(int argc, char* argv[]) {
    char filename[32];
    if (argc < 2) {
        strcpy(filename, "test.wav");
    } else {
        strcpy(filename, argv[1]);
    }

    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Couldn't open %s\n", filename);
        exit(-1);
    }

    WAVheader h = readwavhdr(fp);
    clearscreen();
    wavdata(h, fp);
    fclose(fp);
    getchar();
}
