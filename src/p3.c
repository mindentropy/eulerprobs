#include <stdio.h>

void getNextPrime(int *x) {
	int i = *x;
	(*x)++;
	if(*x == 1) *x++;

	while(i!=1) {
		if(!((*x) % i)) {
			i = *x;
			(*x)++;
		} else {
			i--;
		}
	}

}


int main(int argc, char **argv) {
	unsigned long num = 600851475143;
	int i = 0;
	int prime = 1;
	int largest = 0;

	
	while(num!=1) {
		getNextPrime(&prime);
		if(!(num % prime)) {
			if(largest < prime) largest = prime;
			num /= prime;
			prime = 1;
		}
	}

	printf("Largest : %d\n",largest);
	return 0;
}
