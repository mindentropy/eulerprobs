#include <stdio.h>
#include <math.h>

#define SIZE 2000000

void GeneratePrime(unsigned long int *nextprime) {
	unsigned long int i = sqrt(*nextprime);
	(*nextprime)++;
	

	while(i>1) {
		if((*nextprime) != 2 && !((*nextprime) & 1)) {
			i = floor(sqrt(++(*nextprime)));
			continue;
		} 

		if((*nextprime) % i == 0) {
			i = floor(sqrt(++(*nextprime)));
			continue;
		}

		i--;
	}
}

int main(int argc,char **argv) {
	unsigned long int prime = 1;
	unsigned long int sumofprimes = 0;

	while(1) {
		GeneratePrime(&prime);
//		printf("%ld\n",prime);
		if(prime < SIZE) 
			sumofprimes += prime;
		else
			break;
	}

	printf("%ld ",sumofprimes);
	printf("\n");
	return 0;
}
