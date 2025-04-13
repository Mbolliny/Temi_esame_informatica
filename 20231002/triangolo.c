
/*
Scrivere un algoritmo che acquisisce due valori interi rappresentanti la base e
l’altezza di un rettangolo, ne calcoli l’area e la stampa.
Se il valore della base o il valore dell’altezza e’ negativo o uguale a 0, allora richiedere l’acquisizione di un nuovo valore finche’ questo non e’ positivo.
*/

#include <stdio.h>

#define COST 2

int main (int argc, char * argv []) {

    int base, altezza, area;

    // controllo valore ingresso BASE
    do {

        printf("Inserire la base: ");
        scanf("%d", &base);

        // Messaggio di errore se i valori non sono accettabili
        if (base <= 0) {
            printf("Valori non accettabili. Reinserire valori.\n");
        }

    } while (base <= 0);


    // controllo valore ingresso ALTEZZA
    do {
    
        printf("Inserire l'altezza: ");
        scanf("%d", &altezza);

        // Messaggio di errore se i valori non sono accettabili
        if (altezza <= 0) {
            printf("Valori non accettabili. Reinserire valori.\n");
        }

    } while (altezza <= 0);

    // Calcolo area
    area = (base * altezza) / COST;
    printf("Area:  %d \n", area);

    return 0;
}
