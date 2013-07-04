#include <stdio.h>

int numsize(int val) {
	int size = 0;
	while(val) {
		val /= 10;
		size++;
	}

	return size;
}

unsigned int power(int num, int pow) {
	int i,val = 1;
	for(i = 0;i<pow;i++) {
		val*=num;
	}
	return val;
}

int reversenum(int num) {
	int size = numsize(num);
	int val = 0;

	while(num) {
		val += (num%10) * power(10,--size);
		num /= 10;
	}
	return val;
}

int main(int argc, char **argv) {
	int largest = 0;
	int i = 0, j = 0;

	for(i = 100;i<1000;i++) 
		for(j = 100;j<1000;j++) 
			if(reversenum(i*j) == i*j) 
				if(i*j>largest) largest = i*j;
		
	
	printf("Largest : %d\n",largest);
	return 0;
}
