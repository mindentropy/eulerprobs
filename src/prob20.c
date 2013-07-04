#include <stdio.h>

#define BUFFERSIZE 1024
#define SIZE 100

struct factorial {
	int index;
	unsigned int num[BUFFERSIZE];
};

int main(int argc, char **argv) {
	struct factorial fact;
	unsigned int carry = 0,mult = 0,sum = 0;
	int i,j = 0;

	fact.index = 0;
	for(i = 0;i<BUFFERSIZE;i++) fact.num[i] = 0;

	fact.num[0] = 1;

	for(i = 1;i<=SIZE;i++) {
		carry = 0;
		for(j = 0;j<fact.index+1;j++) { //Multiply with all the numbers.
								//Index keeps track of the length of numbers.
			mult = fact.num[j]*i + carry;
			fact.num[j] = mult%10;
			carry = mult/10;
		}
		//Get the size of carry.
		while(carry!=0) {
			fact.num[++(fact.index)] = carry%10;
			carry /= 10;
		}
	}

	for(i = fact.index;i>=0;i--) {
		printf("%d",fact.num[i]); sum += fact.num[i];
	}

	printf("\nSum : %d\n",sum);
	printf("\n");
	return 0;
}
