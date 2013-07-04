#include <stdio.h>

#define SIZE 10001

void GeneratePrime(int *nextprime) {
	int i = *nextprime;
	(*nextprime)++;

	while(i>1) {
		if((*nextprime) != 2 && !((*nextprime) & 1)) {
			i = (*nextprime)++;
			continue;
		} 

		if((*nextprime) % i == 0) {
			i = (*nextprime)++;
			continue;
		}
		i--;
	}
}

int main(int argc,char **argv) {
	int i = 0;
	int prime = 1;
	for(i = 0; i<SIZE; i++) {
		GeneratePrime(&prime);
	}

	printf("%d ",prime);
	printf("\n");
	return 0;
}
