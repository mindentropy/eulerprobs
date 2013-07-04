#include <stdio.h>

#define SIZE 4000000

int main(int argc, char **argv) {
	unsigned int x=1,y=2;
	int i = 0,tmp = 0;
	unsigned int sum = 0;
	//printf("%d %d ",x,y);
	for(i = 0; ;i++) {
		tmp = x + y;
		if(tmp>SIZE) break;

		if(!(tmp&1)) {
			printf("%d ",tmp);
			sum += tmp;
		}
		x = y;
		y = tmp;
	}

	printf("\nSum : %d \n",sum);
	return 0;
}
