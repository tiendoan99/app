#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include "screen.h"
#include "sound.h"
#include <signal.h>
#include "comm.h"
int main(int argc, char **argv){
	if(argc>1){		// if the user has given some command line argument
		printf("Test tone generator\n");
		int fR, fL, ch;
		float duration;
		printf("No. of channels (1 or 2): ");
		scanf("%d", &ch);
		if(ch == 1){
			printf("Mono frequency: ");
			scanf("%d", &fL); 
		}
		else(ch == 2){
			printf("Give me LEFT and RIGHT freq: ");
			scanf("%d %d", &fL, &fR);
		}
		else{
			printf("Wrong number of channels!\n");
			return 1;
		}
		printf("Duration of sound: ");
		scanf("&f", &duration);
		testTone(ch, fL, fR, duration);
		return 0;
	}
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
		sendDATA(sd);
    }
	resetColors();
//  getchar();
}

