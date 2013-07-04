#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX 1000

uint8_t recur[100] = {0};
uint8_t largestrecur = 0;

int32_t find_recur(uint8_t num,int32_t len) {
	len--;
	while(len >= 0) {
		if(recur[len] == num) {
			return len;
		}
		len--;
	}

	return len;
}

void recur_print(uint8_t len) {
	uint8_t index = 0;

	while(index<len) 
		printf("%u",recur[index++]);
	
	printf("\n");
}

int main(int argc,char **argv) {
	uint8_t denom = 2;
	uint8_t i = 0;
	uint8_t quotient = 0;
	int32_t recur_index = 0;
	uint8_t startnum = 10;

	while(denom<MAX) {
		while(1) {

			quotient = (startnum/denom);
			recur[i++] = quotient;

			if(!(startnum%denom))
				break;

			recur_index = find_recur(quotient,i-1);

			if(recur_index!=-1) {
				recur_print(i);
				printf("denom:%u index:%u\n",denom,i-recur_index-1);

				break;
			}
			
			startnum -= (quotient * denom);
			startnum *= 10;
		}

		i = 0;
		startnum = 10;
		denom++;
	}

	printf("\n");
	return 0;
}
