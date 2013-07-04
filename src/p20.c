#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define LEN 10

#define SELECT 		1
#define NOTSELECT 	0

uint32_t numstr[LEN]	=	{0,1,2,3,4,5,6,7,8,9};
//uint32_t numstr[LEN]	=	{0,1,2};
uint32_t permstr[LEN] 	= 	{0};
uint32_t resultstr[LEN];
uint32_t level = 0;

void picknum(uint8_t *index) {

	while(1) {
		if((*index) == LEN) {
			*index = 0;
		}

		if(permstr[*index] == NOTSELECT) {
			return;
		}

		(*index)++;
	}
}

void perm(uint8_t len) {
	int8_t i = 0;
	uint8_t index = 0;

	if(len == 0) {
		level++;
		printf("%u) ",level);

		for(i = LEN-1;i>=0;i--)
			printf("%u",resultstr[i]);

		printf("\n");
	}

	i = 0;
	while(i<len) {
		picknum(&index);
		//printf("%u ",numstr[index]);

		resultstr[len-1] = numstr[index];

		permstr[index] = SELECT;
		perm(len-1);
		permstr[index] = NOTSELECT;
		index++;
		i++;
	}
}

int main(int argc, char **argv) {
	uint8_t i = 0;

/* 
	For 3
	The first position can be arranged in 3 ways.
	For every 3 ways you can arrange the remaining in 2 ways.
	For every 2 ways the remaining can be arranged in 1 way.
*/
	
	perm(LEN);
	printf("\n");
	return 0;
}
