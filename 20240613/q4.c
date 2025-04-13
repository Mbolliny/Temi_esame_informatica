#include <stdio.h>

#define ERROR -1

int scalare_minimo(float[], float[], float*, int*);  // prototipo

int main() {
    // variabili globali
    float scalare_max;
    int indice_max;
    int i, offset;

    // variabili globali
    scalare_max = 0;
    indice_max = 0;

    // Esempio di array di valori e pesi
    float valori[] = {1.0, -2.0, 2.5, -5.0, 0};  // 5 valori
    float pesi[] = {-3.0, 5.5, 0.0};  // 3 pesi

    // Chiamata al sottoprogramma
    offset = scalare_minimo(valori, pesi, &scalare_max, &indice_max);

    if (offset == ERROR) {
        printf("Errore: la dimensione di valori[] è inferiore a pesi[]\n");
    } else {
        printf("prodotto scalare massimo: %f ", scalare_max);
        printf("calcolato tra gli indici: ");
        for(i = 0; i < offset; i++)
            printf(" %d ", indice_max + i);
    }
    printf(" \n");
    printf(" \n");

    return 0;
}

int scalare_minimo(float valori[], float pesi[], float* scalare_max, int* indice_max) {

    int dim_pesi, dim_valori, num_sottovettori;
    int i, j, offset_valori;
    float scalare;

    // inizializzazione
    dim_valori = 0;
    dim_pesi = 0;
    scalare = 0;
    offset_valori = 0;

    // trovare dimensione array valori[]
    while (valori[dim_valori] != 0) {
        dim_valori++;
    }
    printf(" \n");
    printf("dimensione valori[]: %d\n", dim_valori);

    // trovare dimensione array pesi[]
    while (pesi[dim_pesi] != 0) {
        dim_pesi++;
    }
    printf("dimensione pesi[]: %d\n", dim_pesi);

    if(dim_valori < dim_pesi) {
        printf("Errore: la dimensione di valori[] è inferiore a pesi[]\n");
        return ERROR;
    }

    // calcolo numero combinazioni
    num_sottovettori = (dim_valori - dim_pesi + 1);
    printf("dimensione sottovettori creabili: %d\n", num_sottovettori);
	printf(" \n");

    // ripetizione per sottovettore
    for(i = 0; i < num_sottovettori; i++) {
        printf("sottovettore %d:\n", i);

        scalare = 0;  // reset del prodotto scalare per ogni sottovettore
        for(j = 0; j < dim_pesi; j++) {
            scalare += (valori[(j + offset_valori)] * pesi[j]);  // moltiplicazione con gli stessi pesi[]
            printf("p.scalare indici %d tra %f e %f = %f\n", offset_valori + j, valori[offset_valori + j], pesi[j], valori[offset_valori + j] * pesi[j]);
        }

        // inizializzazione valore massimo
        if(i == 0) {
            *scalare_max = scalare;
            *indice_max = offset_valori;  // salva l'indice iniziale
        }

        // verifica valore massimo e aggiornamento di max;
        if(scalare > *scalare_max) {
            *scalare_max = scalare;
            *indice_max = offset_valori;  // salva l'indice iniziale
        }

        // aggiornamento di offset_valori per passare a prossimo sottovettore
        offset_valori++;

        printf("prodotto scalare %d: %f\n", i, scalare);
        printf("\n");
    }

    return dim_pesi;  // ritorna la dimensione di pesi[]
}
