/*
Scrivere un sottoprogramma cifreparidispari che,
ricevuto in ingresso un numero intero senz’altro positivo num
trasmette al chiamante due valori interi costituiti il primo dalle cifre di num in posizione pari
e il secondo da quelle in posizione dispari. Per esempio, se il sottoprogramma riceve in ingresso l’intero 274820012,
calcola i valori 7801 e 24202 e li trasmette al chiamante.
Nel caso in cui il valore in ingresso abbia una sola cifra, il valore costituito dalle cifre pari da trasmettere è 0.
*/

#include <stdio.h>
#include <math.h>
#define BASE 10

int cifreparidispari(int, int * , int * );

int main() {
    int num = 258652857; // 274820012 Numero fisso per test
    int dispari = 0;     // Variabile per memorizzare le cifre in posizione dispari
    int pari = 0;        // Variabile per memorizzare le cifre in posizione pari

    // Chiamata al sottoprogramma
    int totale_cifre = cifreparidispari(num, &dispari, &pari);

    // Stampa dei risultati
    printf("Numero di cifre: %d\n", totale_cifre);
    printf("Numero dispari: %d\n", dispari);
    printf("Numero pari: %d\n", pari);
    printf(" \n");

    return 0;
}

int cifreparidispari(int num, int * dispari, int * pari) {
    int temp_cifra, ncifre, esponente_pari, esponente_dispari;

    ncifre = 0;
    esponente_pari = 0;
    esponente_dispari = 0;
    temp_cifra = 0;
   
      while (num != 0) {
        
        //printf(" \n");
        //printf("numero: %d\n", num);
        //printf("posizione: %d\n", ncifre);
        
        // estrazione cifra
        temp_cifra = num % BASE;
        //printf("valore estratto: %d\n", temp_cifra);

        // caso pari
        if(ncifre % 2 == 0) {
            *pari += temp_cifra * pow(BASE, esponente_pari);
            esponente_pari++;
            //printf("pari: %d\n", *pari);
        
        // caso dispari
        } else {
            *dispari += temp_cifra * pow(BASE, esponente_dispari);
            esponente_dispari++;
            //printf("dispari: %d\n", *dispari);
        }

        // aggiornamento valori
        ncifre++;
        num /= BASE;
    }
    
    printf(" \n");

    return ncifre;
}

