#include <stdio.h>


int squareofsum(int num) {
	int val = ((num)*(num+1))/2;

	return val*val;
}

int sumofsquares(int num) {
	int sumofsq = 0,i;

	for(i = 0;i<=num;i++) 
		sumofsq += (i*i);

	return sumofsq;
}

int main(int argc, char **argv) {
	printf("%d\n", squareofsum(100) - sumofsquares(100));
	return 0;
}
