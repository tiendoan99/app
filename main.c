#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include "screen.h"
#include "sound.h"
#include <signal.h>
int main(){
	FILE *f;
	short sd[RATE];
	for(;;){
		int ret = system(RCMD);
		if( ret == SIGINT) break;
		f = fopen("test.wav","r");
		if(f == NULL){
			printf("can't open the file\n");
			return 1;
		}
//  int dec[COL], i;
//  srand(time(NULL));
//  for(i=0; COL>i; i++) dec[i] = rand()%70+30;
    	clearScreen();
//    	setColors(RED,bg(YELLOW));
//  barChart(dec);
		struct WAVHDR hdr;
		fread(&hdr, sizeof(hdr), 1, f);		// read WAV header
		fread(&sd, sizeof(sd), 1, f);		// read WAV data
		fclose(f);
		displayWAVHDR(hdr);
		displayWAVDATA(sd);
    }
	resetColors();
//  getchar();
}

