#include <stdio.h>

#define NUM_RIGHE 3
#define NUM_COLONNE 6
#define NUM_STRATI 5

// Dichiarazione del sottoprogramma
int trovaStratoConMenoZero(int *);

int main() {

// Array monodimensionale organizzato visivamente come righe e colonne per strato
    int immagine[NUM_RIGHE * NUM_COLONNE * NUM_STRATI] = {
    // Strato 1
    2, 2, 0, 2, 2, 2,
    2, 1, 0, 2, 0, 2,
    2, 2, 0, 2, 2, 2,

    // Strato 2
    2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 0,
    1, 2, 2, 2, 0, 2,

    // Strato 3
    0, 2, 1, 0, 2, 0,
    2, 2, 2, 0, 2, 2,
    2, 2, 2, 2, 2, 2,

    // Strato 4
    1, 2, 2, 2, 2, 2,
    2, 1, 2, 0, 2, 2,
    2, 2, 2, 2, 2, 2,

    // Strato 5
    2, 2, 2, 1, 2, 2,
    2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2
    };

    // Chiamata al sottoprogramma
    int risultato = trovaStratoConMenoZero(immagine);

    // Stampa del risultato
    printf("Il numero di 1 nello strato con meno 0 è: %d\n", risultato);

    return 0;
}

int trovaStratoConMenoZero(int *immagine) {
    
    int offset, dim;
    int i, j;
    int nzero, less_zero;
    int index, less_zero_index;

   
    index = 0;
    less_zero = NUM_RIGHE * NUM_COLONNE;
    offset = NUM_RIGHE * NUM_COLONNE;
    dim = NUM_RIGHE * NUM_COLONNE * NUM_STRATI;


    for(i = 0; i < dim; i += offset) {

        index++;
        nzero = 0;

        printf("strato: %d\n", index);
        printf("i: %d\n", i);

        for(j = 0 + i; j <  i + offset; j++) {
            printf("j: %d\n", j);
            if(*(immagine + j) == 0)
                nzero++;
        }

        printf("nzero: %d\n", nzero);

        if(nzero < less_zero) {
            less_zero = nzero;
            less_zero_index = index;
        }

        
    }

    return less_zero_index;
}