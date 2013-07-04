#include <stdio.h>

#define MAXDIV 500

unsigned long long int getFactors(unsigned long long int num) {
	unsigned long long int i = 1;
	unsigned long long int numofdivisors = 0;

	while(i<=num) {
		if(num%i == 0) 
			numofdivisors++;
		
		i++;
	}

	return numofdivisors;
}

int main(int argc, char **argv) {
	unsigned long long int i,sum = 1;
	unsigned long long int val;

	for(i = 1; ;i++,sum+=i) {
		val = getFactors(sum);

		if(val > MAXDIV) break;
	}

	printf("%llu , %llu\n",sum,val);
	return 0;
}
