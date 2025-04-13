#include <stdio.h>
#include <ctype.h>  // Per la funzione tolower()

/* prototipi */
void minmaxchar(char *str, char *ptr_max, char *ptr_min);

int main(int argc, char *argv[]) {
    /* dichiarazione */
    char max, min;
    char str[100];  // Array per la stringa

    // Abbino puntatori
    char *ptr_max = &max;
    char *ptr_min = &min;

    /* acquisizione */
    printf("Inserire la stringa: ");
    scanf("%s", str);  // Leggi la stringa

    /* chiamata sottoprogramma */
    minmaxchar(str, ptr_max, ptr_min);  // Passa la stringa e i puntatori

    /* stampa risultato */
    printf("%c %c\n", *ptr_min, *ptr_max);

    return 0;
}

/* sottoprogramma */
void minmaxchar(char *str, char *ptr_max, char *ptr_min) {
    /* dichiarazione */
    int i;

    /* inizializzazione */
    *ptr_max = 'a';  // inizializza il massimo
    *ptr_min = 'z';  // inizializza il minimo

    /* operazioni */
    for (i = 0; *(str + i) != '\0'; i++) {
        *(str + i) = tolower(*(str + i));  // Converte ogni carattere a minuscolo

        if (*(str + i) > *ptr_max)
            *ptr_max = *(str + i);

        else if (*(str + i) < *ptr_min)
            *ptr_min = *(str + i);
    }
}

