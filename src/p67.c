#include <stdio.h>
#include <stdlib.h>

#define LEVEL 100

struct numnode {
	int num;
	unsigned long int intersum;
};

struct numnode *numnodes[LEVEL];

void add(unsigned long int i) {
	unsigned long int k = 0;
	if(i == 0) { //Root
		numnodes[i][i].intersum += numnodes[i][i].num;
		return;
	} 

	/* Go to top level. */ 
	i = i - 1;
	
	for(k = 0; k<i+1; k++) {
		/*Go below. Add. */
		if((numnodes[i+1][k].num+numnodes[i][k].intersum) > numnodes[i+1][k].intersum)
			numnodes[i+1][k].intersum = numnodes[i+1][k].num+numnodes[i][k].intersum;

		/*Go below and right one step. Add */
			if((numnodes[i+1][k+1].num+numnodes[i][k].intersum) > numnodes[i+1][k+1].intersum)
				numnodes[i+1][k+1].intersum = numnodes[i+1][k+1].num+numnodes[i][k].intersum;
		
	}
}

int main(int argc, char **argv) {
	unsigned long int i = 0,j = 0,number,largest = 0;
	char num[3];

	FILE *file;
	
	file = fopen("test3.txt","r");
	
	for(i = 0;i<LEVEL;i++) {
		numnodes[i] = malloc(sizeof(struct numnode)*(i+1));
		for(j = 0; j<i+1; j++) {
			fread(num,sizeof(char),2,file);
			num[2] = '\0';
			number = atoi(num);
			printf("%02ld ",number); 
			numnodes[i][j].num = number;
			numnodes[i][j].intersum = 0;
			fread(num,sizeof(char),1,file);  /* Read newline or space*/
		}
		printf("\n"); 
	}

	
	for(i = 0;i<LEVEL;i++) 
		add(i); 
	
	printf("Printing \n");
	for(i = 0;i<LEVEL;i++) {
		if(largest < numnodes[LEVEL-1][i].intersum)
			largest = numnodes[LEVEL-1][i].intersum;
	}

	printf("Largest : %ld\n",largest); 

	return 0;
}
