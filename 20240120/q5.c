#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura per un punto
typedef struct {
    int x;  // Coordinata x del punto
    int y;  // Coordinata y del punto
} coordinate_s;

// Dichiarazione del sottoprogramma
int calcolaLunghezzaPercorso(coordinate_s punti[], int npunti);

int main() {
    // Array di punti
    coordinate_s punti[] = {
        {1, 3}, {4, 3}, {4, 9}, {-4, 9}, {-5, -3}, {2, 1}
    };
    
    // Numero di punti
    int npunti = sizeof(punti) / sizeof(punti[0]);

    // Calcolo e stampa della lunghezza del percorso
    int lunghezza = calcolaLunghezzaPercorso(punti, npunti);
    
    printf("La lunghezza del percorso è: %d\n", lunghezza);

    return 0;
}

int calcolaLunghezzaPercorso(coordinate_s punti[], int npunti) {
    int lunghezza = 0;

    for (int i = 0; i < npunti - 1; i++) {
        // Calcola la distanza di Manhattan
        lunghezza += abs(punti[i + 1].x - punti[i].x) + abs(punti[i + 1].y - punti[i].y);
    }

    return lunghezza;
}
