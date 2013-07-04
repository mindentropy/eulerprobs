#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define LIMIT 28123

unsigned sum = 0;

uint32_t abundant_arr[9000];
uint32_t abundant_sum[LIMIT] = {0};

uint8_t is_abundant(uint32_t num) {
	uint32_t i = num-1;
	uint32_t sum = 0;

	while(i >= 1) {
		if((num%i) == 0) {
			sum = sum + i;

			if(sum > num)
				return 1;
		}
		i--;
	}

	return 0;
}	

int main(int argc,char **argv) {
	uint32_t i = 0,j = 0;
	uint32_t index = 0;
	uint32_t sumindex = 0;

	uint32_t sum = 0;

	for(i = 2;i<LIMIT;i++) {
		if(is_abundant(i)) {
			abundant_arr[index++] = i;
		}
	}
	
	printf("index : %u\n",index);

	/*for(i = 0;i<index;i++) 
		printf("%u\n",abundant_arr[i]);*/
	

	for(i = 0;i<index;i++) {
		for(j = i;j<index;j++) {
			if(abundant_arr[i] + abundant_arr[j] < LIMIT)
				abundant_sum[abundant_arr[i] + abundant_arr[j]] = 1;
		}
	}
	
	sum = 0;
	for(i = 0;i<LIMIT;i++) {
		if(abundant_sum[i] == 0) {
			sum += i;
		}
	}

	printf("sum : %u\n",sum);
	return 0;
}
