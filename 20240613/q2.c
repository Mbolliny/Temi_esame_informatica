#include <stdio.h>
#include <ctype.h>

#define VERO 1
#define FALSO 0

// Prototipo della funzione
int attacco(char []);

int main() {
    // Dichiarazione variabili
    char str[100];
    int risultato;

    // Input dell'utente
    printf(" \n");
    printf("*************\n");
    printf("Inserisci una stringa: ");
    gets(str);

    // Chiamata alla funzione attacco
    risultato = attacco(str);

    // Output del risultato
    if (risultato == VERO) {
        printf("1 - Condizione soddisfatta: sequenza valida.\n");
    } else {
        printf("0 - Condizione non soddisfatta: sequenza non valida.\n");
    }

    printf("*************\n");
    printf(" \n");
    return 0;
}


int attacco(char str[]) {
    /* dichiarazione */
    char save;
    int flag, exit, i, count;

    /* inizializzazione */
    i = 1;
    count = 0;
    exit = FALSO; 
    flag = 0;


    /* salvataggio elemento da confrontare */
    save = tolower(str[0]);

    /* debug 
    printf("************** \n");
    printf("Stringa inserita: %s\n", str);
    printf("Valore salvataggio: %c\n", save); // Corretto il formato di output
    */

    
    while (str[i] != '\0') {

        printf("carattere: %c\n", str[i]);
        if(isalpha(str[i])) {
            if((tolower(str[i]) == save) && (flag != 0)) {
                count++;
            }
            i++;
        } 
        else {
            flag ++;
            while (str[i] != '\0' && !isalpha(str[i])) {
                //printf("i - secondo while: %d\n", i); // Corretto il formato di output
                i++;
            }
        }        
    
        /* debug         
        printf("i - primo while: %d\n", i); // Corretto il formato di output
        printf("count: %d\n", count);
        printf("flag: %d\n", flag);
        printf("**************\n");
        */
    }

    printf("count: %d\n", count);
    printf("flag: %d\n", flag);

    if(flag == count)
        exit = VERO;

    return exit;
}
