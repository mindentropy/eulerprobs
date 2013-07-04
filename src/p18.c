#include <stdio.h>

#define INTERSUM_SIZE 64536*2

#define LEVEL 100 

struct numnode {
	int num;
	unsigned int intersum[INTERSUM_SIZE];
	unsigned long int index;
};

struct numnode numnodes[LEVEL][LEVEL];

void add(unsigned long int i) {
	unsigned long int k = 0,j = 0;
	if(i == 0) { //Root
		numnodes[i][i].intersum[numnodes[i][i].index] = 0;
		numnodes[i][i].intersum[numnodes[i][i].index++] += numnodes[i][i].num;
		return;
	}

	/* Go to top level. */ 
	i = i - 1;
	
	for(k = 0; k<i+1; k++) {
		/*Go below. Add. */
		numnodes[i+1][k].intersum[numnodes[i+1][k].index] = 0;

		for(j = 0;j<numnodes[i][k].index;j++) {
			numnodes[i+1][k].intersum[numnodes[i+1][k].index++] = numnodes[i+1][k].num
																+numnodes[i][k].intersum[j];
			printf("%ld,%ld = %d ",i+1,k,numnodes[i+1][k].intersum[numnodes[i+1][k].index-1]);
		}

		/*Go below and right one step. Add */
		for(j = 0;j<numnodes[i][k].index;j++) {
			numnodes[i+1][k+1].intersum[numnodes[i+1][k+1].index] = 0;
			numnodes[i+1][k+1].intersum[numnodes[i+1][k+1].index++] = numnodes[i+1][k+1].num
																+numnodes[i][k].intersum[j];

			printf("%ld,%ld = %d ",i+1,k+1,numnodes[i+1][k+1].intersum[numnodes[i+1][k+1].index-1]); 
		}
		printf("\n");
	}

}

int main(int argc, char **argv) {
	unsigned long int i = 0,j = 0,number,largest = 0;
	char num[3];

	FILE *file;
	
	file = fopen("test3.txt","r");
	
	for(i = 0;i<LEVEL;i++) {
		for(j = 0; j<i+1; j++) {
			fread(num,sizeof(char),2,file);
			num[2] = '\0';
			number = atoi(num);
			printf("%02ld ",number); 
			numnodes[i][j].num = number;
			numnodes[i][j].index = 0;
			fread(num,sizeof(char),1,file); /* Read newline or space*/
		}
		printf("\n"); 
	}

	
	for(i = 0;i<LEVEL;i++) 
		add(i); 
	
	printf("Printing \n");
	for(i = 0;i<LEVEL;i++) {
		for(j = 0;j<numnodes[LEVEL-1][i].index;j++) {
			if(largest < numnodes[LEVEL-1][i].intersum[j]) 
				largest = numnodes[LEVEL-1][i].intersum[j];
		}
		printf("Index size : %ld \n",numnodes[LEVEL-1][i].index); 
	}
			

	printf("Largest : %ld\n",largest); 

	return 0;
}
