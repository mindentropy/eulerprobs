#include <stdio.h>

#define SIZE 1000000

unsigned long long int GetCollatzSeqSize(unsigned long long int num) {
	unsigned long long int seqsize = 1;
//	printf("%lu ",num);
	while(num!=1) {
		if((num & 1)) {  /* If odd */
			num = (3*num) + 1;
		//	printf("%lu ",num);
		}else {
			num = num>>1;
		//	printf("%lu ",num);
		}
		seqsize++;
	}

	return seqsize;
}

int main(int arg,char **argv) {
	unsigned long long int i = 1,largest = 0,val = 0;
	unsigned long long int startnum = 0;

	for(i = 1;i<SIZE;i++) {
		val = GetCollatzSeqSize(i);
		if(largest < val)  {
			largest = val;
			startnum = i;
		}
	
		//printf("|%lu : size : %lu \n",i,val); 
	}
	
	printf("Largest :  %llu\n",startnum);
	return 0;
}
