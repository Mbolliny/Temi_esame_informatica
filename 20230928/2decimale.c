#include <stdio.h>

#define COST1 0.5
#define COST2

int main (int argc, char * argv[])
{

	float num, ParteDecimale;
	int ParteIntera, eccesso;

	printf("inserire numero: ");
	scanf("%f", &num);

	// seaparazione parte intera
	ParteIntera = (int)num;

	// seaprazione parte decimale
	ParteDecimale = num - ParteIntera;

	// condizioni
	if (ParteDecimale > COST1) {
		
		eccesso = ParteIntera + (COST1 * COST2);

		printf("arrotondo per eccesso - numero: %d \n", eccesso);
	
	} else printf("arrotondo per difetto - numero: %d \n", ParteIntera);

	return 0;
}