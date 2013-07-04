#include <stdio.h>

#define SIZE 10000

unsigned long sumarr[SIZE];

int main(int argc,char **argv) {
	int i,j = 0; 
	unsigned long sum = 0;
	for(i = 1;i<SIZE;i++) {
		for(j = i-1; j>0; j--) {
			if(!(i%j)) {
				sumarr[i] += j;
			}
		}
	}

	
	 for(i = 1;i<SIZE;i++) {
		if((sumarr[i] < SIZE) && (i == sumarr[sumarr[i]]) && (i!=sumarr[i])) {
			printf("%u , %lu \n",i,sumarr[i]);
			sum += i;
		}
	}
	
	printf("Amicable sum : %lu\n",sum);

	return 0;
}
