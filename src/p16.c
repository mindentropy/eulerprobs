#include <stdio.h>

#define NUM 1000
#define NUMSIZE 1000

int main(int argc,char **argv) {
	unsigned int ch[NUMSIZE] = {0};
	unsigned int i,j,carry = 0;
	unsigned int numsize = 0,sum = 0;
	int x = 0;

	ch[0] = 1;
	
	for(i = 0;i<NUM;i++) {
		for(j = 0; j<NUMSIZE; j++) {
			if(ch[j] == 0 && j>numsize) {
				ch[j] += carry;
				if(carry != 0) numsize++;
				break;
			}
			ch[j] = (ch[j]*2) + carry;
			carry = ch[j]/10;
			ch[j] %= 10;
		}
		carry = 0;
	}
	
	printf("numsize : %d\n",numsize);
	for(x = numsize;x>=0;x--) {
		printf("%d",ch[x]);
		sum += ch[x];
	}
	printf("\n");
	
	printf("Sum : %d\n",sum);
	return 0;
}
