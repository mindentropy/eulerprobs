#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

#define ROWS 100
#define COLS 50

unsigned char num[ROWS][COLS] = {{1,2},{9,5}};
unsigned char finalsum[COLS];

int main(int argc, char **argv) {
	int i,j,fd;
	unsigned int sum,carry = 0;
	unsigned char number;

	fd = open("num.txt",O_RDONLY);
	for(i = 0;i<ROWS;i++) {
		for(j = 0;j<COLS;j++) {
			read(fd,&number,1);
			num[i][j] = atoi(&number);
		}
		read(fd,&number,1); // Read newline.
	}
	close(fd); 
	
	for(i = COLS-1;i>=0;i--) {
		sum = 0;
		for(j = ROWS-1;j>=0;j--) {
			sum += num[j][i];
		}
		sum += carry;
		finalsum[i] = (sum%10);
		carry = sum/10;
	}
	
	printf("%d",carry);
	for(i = 0;i<COLS;i++) {
		printf("%d",finalsum[i]);
	}
	printf("\n");
	return 0;
}
