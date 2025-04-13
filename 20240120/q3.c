/*
Per impostare una combinazione per un lucchetto numerico vengono indicate le seguenti regole:
• deve essere un numero di 6 cifre
• ci devono essere due cifre adiacenti uguali
• da sinistra verso destra lecifre non sono mai decrescenti :o crescono o rimangono uguali (come in 111123 oppure 135679)

A titolo di esempio, sono vere le seguenti affermazioni:
111111 - rispetta le regole (doppio 1 e mai decrescente)
223450 - non rispetta le regole (cifre decrescenti 50)
123789 - non rispetta le regole (non ci sono due cifre adiacenti uguali)

Scrivere un sottoprogramma verifica che ricevuto in ingresso un valore intero positivo restituisce 1 se è una combinazione valida, 0 altrimenti.
*/

#include <stdio.h>

#define VALIDA 1
#define NONAVALIDA 0
#define BASE 10

// Prototipo della funzione che verifica la combinazione
int verifica_combinazione(int numero);

int main() {
    int numero;

    // Acquisizione del numero
    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    // Verifica se la combinazione è valida
    if (verifica_combinazione(numero) == VALIDA) {
        printf("Combinazione valida\n");
    } else {
        printf("Combinazione non valida\n");
    }

    return 0;
}

// Sottoprogramma per verificare la combinazione
int verifica_combinazione(int num) {
    int count = 0;
    int coppia = 0;
    int trovato = VALIDA;
    int cif, prev = -1;

    while (num != 0) {
        cif = num % BASE;  // Ottieni l'ultima cifra
        num /= BASE;  // Rimuovi l'ultima cifra

        count++;  // Incrementa il conteggio delle cifre

        // Confronta la cifra corrente con la precedente
		if (cif > prev)
                trovato = NONAVALIDA;  // La sequenza è invalida se è crescente
            
        if (cif == prev) 
                coppia++;  // C'è una coppia di cifre uguali

        prev = cif;  // Salva la cifra corrente per il prossimo confronto
    }

    // Se il numero non ha esattamente 6 cifre, non è valido
    if (count != 6 && coppia == 3) {
        trovato = NONAVALIDA;
    }

    return trovato;
}
