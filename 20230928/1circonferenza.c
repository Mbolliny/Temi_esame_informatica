/*
Si realizzi un programma in linguaggio C ANSI che acquisisce un valore intero positivo
(è senz’altro così) che rappresenta il raggio di una circonferenza e calcola e
visualizza il perimetro e l’area.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14
#define COST 2

int main (int argc, char * argv[]) 
{
	int raggio;
	int circ;
	int area;
	
	printf("Inserire raggio: ");
	scanf("%d", &raggio); // &raggio è necessario


	// calcolo
	area = PI * pow(raggio,2);
	circ = COST * PI * raggio;

	// stampa dei risultti
	printf("Valore circonferenza: %d \n", circ);
	printf("Valore area: %d", area);

	return 0;
}