#include <stdio.h>


int main(int argc,char **argv) {
	int i,j,k;
	
	/* i<j<k */
	for(i = 1;i<998;i++) { 
		for(j = i+1; j<999; j++) {
			for(k = j+1;k<1000;k++) {
				if((i*i) + (j*j) == (k*k) && (i+j+k) == 1000) {
					printf("%d %d %d : %d\n",i,j,k,(i*j*k));
					return 0;
				}
			}
		}
	}
	
	return 0;
}
