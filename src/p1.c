#include <stdio.h>

#define SIZE 1000

int main(int argc, char **argv) {
	short i = 0;
	unsigned int sum = 0;

	for(i = 1;i<SIZE;i++) 
		if(!(i%3) || !(i%5))  
			sum+=i;

	printf("Sum : %d\n",sum);
	return 0;
}
