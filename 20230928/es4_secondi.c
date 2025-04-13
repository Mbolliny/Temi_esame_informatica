#include <stdio.h>

#define MIN 60
#define ORE 60
#define GG 24

int main (int argc, char * argv [])
{
	
	int sec, min, h;
	int tot_s, tot_min, tot_h, tot_gg;

	printf("inseririe numero di sec da convertire: ");
	scanf("%d", &tot_s);

	tot_min = tot_s / MIN; // 1728
	tot_h = tot_min / ORE; // 1029
	tot_gg = tot_h / GG; // 1

	/* 
	//debug
	printf("tot sec: %d \n", tot_s);
	printf("tot min: %d \n", tot_min);
	printf("tot h: %d \n", tot_h);
	printf("tot giorni: %d \n", tot_gg);
	*/
	
	h = tot_h - (tot_gg * GG); // 29 - 24 
	min = tot_min - (tot_h * ORE); // 1762 - 1740
	sec = tot_s - (tot_min * MIN); // 

	printf("numero sec: %d \n", sec);
	printf("numero min: %d \n", min);
	printf("numero h: %d \n", h);
	printf("numero giorni: %d \n", tot_gg);
	
	return 0;
}