#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum {
	MON,
	TUE,
	WED,
	THU,
	FRI,
	SAT,
	SUN
}DAY;

uint32_t suncnt = 0;

uint32_t yrcnt = 1900;
uint32_t monthcnt = 1;
uint32_t daycnt = 1;
DAY day = MON;

void printday(DAY day) {
	switch(day) {
		case MON:
			printf("mon ");
			break;
		case TUE:
			printf("tue ");
			break;
		case WED:
			printf("wed ");
			break;
		case THU:
			printf("thu ");
			break;
		case FRI:
			printf("fri ");
			break;
		case SAT:
			printf("sat ");
			break;
		case SUN:
			printf("sun ");
			break;
	}
}

void printdate(uint32_t day,uint32_t month,uint32_t year) {
	printf("%u-%u-%u\n",day,month,year);
}

int main(int argc,char **argv) {
	
	while(yrcnt <= 2000) {
		if((yrcnt > 1900) && (day == SUN) && (daycnt == 1)) {
			suncnt++;
		}

		if(monthcnt == 2) {
			if((daycnt == 28) && ((yrcnt % 4) == 0)) {
				if((yrcnt % 100) == 0 && (yrcnt % 400) == 0) {
					daycnt++;
				} else if((yrcnt % 100) != 0){
					daycnt++;
				} else if((yrcnt % 100) == 0 && (yrcnt%400) != 0){
					daycnt = 1;
					monthcnt++;
				}
			} else if((daycnt == 28) && ((yrcnt%4) != 0)) {
				daycnt = 1;
				monthcnt++;
			} else if(daycnt == 29) {
				daycnt = 1;
				monthcnt++;
			} else {
				daycnt++;
			}
		} else if((daycnt == 30) && 
					((monthcnt == 4) || (monthcnt == 6) ||(monthcnt == 9) ||(monthcnt == 11))) { //If apr,jun,sept and nov.
			daycnt = 1;
			monthcnt++;
		} else if((daycnt == 31) && 
				((monthcnt == 1) || (monthcnt == 3) || (monthcnt == 5) || (monthcnt == 7) || (monthcnt == 8) || (monthcnt == 10) ||
					(monthcnt == 12)) ) {
			daycnt = 1;
			monthcnt++;

			if(monthcnt == 13) {
				monthcnt = 1;
				yrcnt++;
			}

		} else {
			daycnt++;
		}


		if(day == SUN) {
			day = MON;
		} else {
			day++;
		}
		
		printday(day);
		printdate(daycnt,monthcnt,yrcnt);
	}
	
	printf("suncnt : %u\n",suncnt);

	return 0;
}
