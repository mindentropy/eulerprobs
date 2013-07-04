#include <stdio.h>

#define MAX 10000


int main(int argc, char **argv) {
	int i = 0,j,index = 0;
	unsigned int sums[MAX];

	for(i = 2;i<MAX;i++) 
		for(j = i-1;j>1;j--) 
			if(i%j == 0) 
				sums[index++] = j;
			

	printf("Sum size : %d\n",index);
	return 0;
}
