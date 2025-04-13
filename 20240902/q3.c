#include <stdio.h>

#define BASE 10
#define START 0


// Dichiarazione del prototipo della funzione istogramma
void istogramma(int val, char ch);

int main() {
    int val = 123456789; // Esempio di valore intero da analizzare
    char ch = '*';  // Carattere da utilizzare per l'istogramma

    printf("Valore: %d\n", val);
    //printf("Carattere: %c\n", carattere);
    
    // Chiamata alla funzione istogramma
    istogramma(val, ch);

    return 0;
}

// Definizione della funzione istogramma
void istogramma(int val, char ch) {
    int count;
    int toscroll;
    int tofind;

    // valore da cercare
    tofind = START;

    // Iterazione finché il valore non è zero
    while (tofind < 10) {

   		toscroll = val;
        count = 0;
		
		//printf(" \n");
        //printf("cerco: %d\n", tofind);
        
        // Conteggio delle occorrenze
        while (toscroll != 0) {
            if (toscroll % BASE == tofind)
                count++;

            toscroll /= BASE;
        }

        // Stampa del risultato
        if(count != 0) {
        	printf("%d : ", tofind);

	        for (int i = 0; i < count; i++)
	            printf("%c", ch);
        	
        	printf("\n");
        }

        tofind++;
    }
}
