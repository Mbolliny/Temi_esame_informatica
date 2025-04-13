/*
Scrivere un algoritmo che legga in ingresso una sequenza di numeri interi (stret-tamente positivi) e ne calcoli massimo, minimo e media. 

La sequenza si inter-rompe appena viene introdotto un numore minore o uguale di zero. 

Una volta interrotta la sequenza i numori di massimo, minimo e media vengono stampati.

Se il primo numore inserito e’ negativo, il programma restituisce 0.
Es. Data la sequenza 5, 1, 2, 3, 4, -5−− > max = 5, min = 1, media = 3
*/

#include <stdio.h>

#define COST 500

int main (int argc, char * argv []) {

	int num;
	int max, min;
	int sum, i;
	float media;

	sum = 0, i = 0, max = 0;

	// Inserimento del primo numero
    printf("Inserire valore: ");
    scanf("%d", &num);

    // Se il primo numero è negativo o zero, termina il programma con output 0
    if (num <= 0) {
        printf("numero negativo o zero - STOP\n");
        return 0;
    }

    // Inizializza max e min con il primo valore positivo
    max = num;
    min = num;
    sum += num;
    i++;

    // Ciclo do-while per leggere i numeri finché l'input è positivo
    do {
        printf("Inserire valore: ");
        scanf("%d", &num);


            // Aggiorna max e min
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }

            // Aggiorna somma e conteggio
            sum += num;
            i++;
        
    } while (num > 0);


    // Calcola la media
    media = (float)sum / i;

		//stampa
		printf(" \n");
		printf("contatore i: %d \n", i);
		printf("somma: %d \n", sum);

		//stampa
		printf(" \n");
		printf("MAX: %d \n", max);
		printf("MIN: %d \n", max);
		printf("MEDIA: %f \n", media);

	return 0;
}