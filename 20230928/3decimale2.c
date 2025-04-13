#include <stdio.h>

#define COST 0.5

int main (int argc, char * argv[])
{

	float num, ParteDecimale;

	printf("inserire numero: ");
	scanf("%f", &num);

	// seaparazione parte decimale
	ParteDecimale = (float)num;

	printf("parte decimale: %f \n", ParteDecimale);


	return 0;
}