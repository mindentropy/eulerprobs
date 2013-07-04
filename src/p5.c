#include <stdio.h>

#define SIZE 20
int checkDivisible(int num) {
	int i = SIZE;

	while(i>0) {
		if(num%i) 
			return i;
		i--;
	}

	return i;
}

int main(int argc, char **argv) {
	int i = SIZE;

	while(1) {
		if(checkDivisible(i) == 0) 
			break;
		
		i++;
	}

	printf("%d\n",i);
	return 0;
}
