#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

char names[6000][30];
int row = 0,col = 0;
int fd = 0;
unsigned int score[6000];

int parsename() {
	char ch = 0;
	int ret = 0;
	col = 0;

	while(ret = read(fd,&ch,1)) {
		if(ch == '\"') {
			read(fd,&ch,1);
			names[row][col] = '\0';
			row++;
			
			if(ch != ',') //End of the list.
				return -1;

			return 1;
		}
		names[row][col++] = ch;
	}
	return -1; //Some error. Should never happen.
}

void strswap(int k) {
	char temp[30];
	
	strcpy(temp,names[k]);
	strcpy(names[k],names[k-1]);
	strcpy(names[k-1],temp);
}

void sort_names() {
	int i = 0;
	int k = 0;

	for(i = 0;i<row;i++) {
		k = i;
		while(k > 0) {
			if(strcmp(names[k],names[k-1]) < 0) {
				strswap(k);
			} else {
				break;
			}
			k--;
		}
	}
}

void compute_score(int i) {
	int len = strlen(names[i]);
	int j = 0;
	unsigned char ch = 'A';

	score[i] = 0;

	for(j = 0;j<len;j++) {	
		score[i] += names[i][j]-(unsigned)ch+1;
	}
	
	score[i] = score[i] * (i+1);
}

int main(int argc, char **argv) {
	int ret = 0;
	char ch = 0;
	int maxnames = 0;
	int i = 0;
	unsigned long total = 0;

	fd = open("names.txt",O_RDONLY);
	
	while(ret = read(fd,&ch,1)) {
		if(ch == '\"') {
			if(parsename() == -1) break;
		}
	}

	/*for(i = 0;i<row;i++)
		printf("%d) %s\n",i,names[i]);*/
	
	sort_names();

	for(i = 0;i<row;i++) {
		printf("%d) %s\n",i,names[i]);
		compute_score(i);
		total += score[i];
	}
	
	printf("%lu\n",total);
	close(fd);
	return 0;
}
