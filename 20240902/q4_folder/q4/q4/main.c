#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Prototipo del sottoprogramma
void stringa_piu_lunga(char []);

int main() {
    char frase[] = "correttamente sottoprogramma"; //
    //char frase[] = "abc abcd "; //

    // Chiamata al sottoprogramma
    stringa_piu_lunga(frase);

    return 0;
}

// Sottoprogramma per trovare il vocabolo più lungo
void stringa_piu_lunga(char str[]) {
    int i, max_index, count, max_count;
    char longest[30];  // Array statico per contenere la parola più lunga

    // inizializzazione
    count = 0;
    max_count = 0;
    max_index = 0;
    
    printf(" \n");
    for (i = 0; *(str + i) != '\0'; i++) {
        if (isalpha(*(str + i))) {
            count++;
        } else {
            if (count > max_count) {
                max_count = count; // Aggiorna la lunghezza massima
                max_index = i - max_count;
            }
            count = 0; // Ripristina il contatore per il prossimo vocabolo
        }
    }

    // gestione dell'ultimo vocabolo
    if (count > max_count) {
        max_count = count;
        max_index = i - max_count;
    }

    
 
    // stringa di ritorno
    /* **** versione con malloc ***
 
    // 2 - allocare la memoria per la stringa
    longest = (char *)malloc((max_count + 1) * sizeof(char));  // +1 per '\0'

    if (longest) {
        // Copiare la parola più lunga nella nuova stringa
        for (i = 0; i < max_count; i++) {
            longest[i] = str[max_index + i];  // copia carattere per carattere
        }
        longest[max_count] = '\0';  // termina la stringa con '\0'

        // Stampa il risultato
        printf("Il vocabolo più lungo è: %s\n", longest);

        // Liberare la memoria allocata
        free(longest);
    
    } else {
        // Errore nell'allocazione della memoria
        printf("Errore nell'allocazione della memoria\n");
    }
    */

    /* **** versione con strcopy *** */
    // Copia la parola più lunga nella nuova stringa usando strcpy
    strncpy(longest, &str[max_index], max_count); // Copia max_count caratteri da str[max_index] a longest
    //longest[max_count] = '\0';  // Termina la stringa con '\0'

    // Stampa il risultato
    printf("Il vocabolo più lungo è: %s\n", longest);
}
