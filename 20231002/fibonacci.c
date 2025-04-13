/*
La successione di Fibonacci `e una successione di numeri interi positivi in cui ciascun numero a cominciare dal terzo `e la somma dei due precedenti e i primi due sono 1, 1.
Scrivere il diagramma di flusso di un algoritmo che acquisisce un intero n senz’altro strettamente maggiore di 2), e che stampi i primi n numeri della successione di Fibonacci.
Esempio (n = 10): 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
*/

#include <stdio.h>

int main (int argc, char * argv[]) {
	
	int a,b,c;
	int i;

	i = 0;
	a = 1, b = 1;

	printf("sequenza: %d %d", a, b);

	for (i = 0 ; i < 8; i++) {

		c = a + b;
		printf(" %d", c);

		a = b;
		b = c;
	
	}

	return 0;
}