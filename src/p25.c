#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX 12L

#define MAXLEN 	1000
#define MAXSIZE 2000

struct num {
	uint8_t number[MAXSIZE];
	int32_t numlen;
};


void addnum(struct num *a,struct num *b,struct num *result) {
	uint32_t index = 0;
	uint32_t numsize = 0;
	uint32_t res = 0,carry = 0;

	result->numlen = 0;

	if(a->numlen > b->numlen) 
		numsize = a->numlen;
	else 
		numsize = b->numlen;
	
	
	while(index<numsize) {
		res = (a->number[index]) + (b->number[index]) + carry;
		carry = res/10;
		res = res%10;
		result->number[index] = res;
		result->numlen++;
		index++;
	}

	if(carry) {
		result->number[index] = carry;
		result->numlen++;
	}
}

void copyresult(struct num *src, struct num *dest) {
	uint32_t index = 0;
	dest->numlen = 0;

	while(index < (src->numlen))
		dest->number[(dest->numlen)++] = src->number[index++];
	
}

void printresult(struct num *result) {
	int32_t index = (result->numlen)-1;

	while(index>=0) {
		printf("%u",result->number[index--]);
	}
	printf("\n");
}

int main(int argc,char **argv) {
	uint64_t index = 1L;
/*	uint64_t prev = 0L;
	uint64_t fib = 1L;
	uint64_t tmp = 0L;*/
	struct num prev;
	struct num fib;
	struct num result;

	memset(prev.number,0,MAXSIZE);
	memset(fib.number,0,MAXSIZE);
	memset(result.number,0,MAXSIZE);

	prev.number[0] = 0;
	prev.numlen = 1;

	fib.number[0] = 1;
	fib.numlen = 1;

	result.numlen = 0;

	while(1) {
		printf("%llu) ",index);
		printresult(&fib);
		
		if(fib.numlen == MAXLEN)
			break;

		addnum(&fib,&prev,&result);
		copyresult(&fib,&prev);
		copyresult(&result,&fib);

/*		tmp = fib;
		fib = fib + prev;
		prev = tmp;*/
		index++;
	}

	printf("\n");
	return 1;
}
