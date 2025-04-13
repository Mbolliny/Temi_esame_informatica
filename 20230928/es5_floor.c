#include <stdio.h>
#include <math.h>

#define POS 1
#define NEG 0

int main (int argc, char * argv[])
{

	int a, l ,lato;
	int floor, tile, num;
	int resto;

	printf("\n");
	
	printf("inserire altezza pavimento: ");
	scanf("%d", &a);

	printf("inserire larghezza pavimento: ");
	scanf("%d", &l);
	
	printf("inserire dimensioni piastrella: ");
	scanf("%d", &lato);

	printf("\n");

	
	floor = a * l; // area pavimento
	tile = pow(lato,2); // area piastrella

	num = floor / tile; // numero tot piastrelle
	resto = floor % tile; // numero tot piastrelle

	printf("numero tot piastrelle: %d ", num);

	if (resto > 0) {

		printf(", MA servono altre piastrelle - %d \n", POS);

	} else printf("e NON servono altre piastrelle - %d \n", NEG);

	
	return 0;
}