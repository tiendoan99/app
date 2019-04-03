#include <stdio.h>
#include "sound.h"
#include <math.h>

void showID(char *idname,char *id){
	int i;
	printf("%s : ", idname);
	for(i=0; i<4; i++)
		printf("&c", id[i]);
	puts("");
}

// this function gets 1 second of samples (16000), and calculates
// 80 pieces of decibel value, we know we need to calculate 1 decibel
// value form 200 samples, decibel value is calcualted by RMS formula
void displayWAVDATA(short s[]){
	double rms[80];
	short *ptr = s;		// we use a pointer, pointing to the beginning of array
	int i, j;			// for nested loop counters, outer loop repeats 80 times
						// inner loop repeats 200 times
	for(i=0; i<80; i++){
		double sum = 0;		// accumulate sum of squares
		for(j=0; j<200; j++){
			sum += (*ptr) * (*ptr);
			ptr++;			// pointing to the next sample
		}
		rms[i] = sqrt(sum/200);
		printf("rms[%d] = %f\n", i , rms[i]);
	}
}

void displayWAVHDR(struct WAVHDR h){
	showID("ChunkID", h.ChunkID);
	printf("Chunk size: %d\n", h.ChunkSize);
	showID("Format", h.Format);
	showID("Subchunk1ID", h.Subchunk1ID);
	printf("Subchunk1 size: %d\n", h.Subchunk1Size);
	printf("Audio format: %d\n", h.AudioFormat);
	printf("Number of channels: %d\n", h.NumChannels);
 	printf("Sample rate: %d\n", h.SampleRate);
 	printf("Byte rate: %d\n", h.ByteRate);
 	printf("Block align: %d\n", h.BlockAlign);
 	printf("Bits per sample: %d\n", h.BitsPerSample);
	showID("Subchunk1ID", h.Subchunk1ID);
	printf("Subchunk2 size: %d\n", h.Subchunk2Size);
}