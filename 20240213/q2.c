#include <stdio.h>

#define DIM 40
#define BASE 10

void calibra(char *, int *, int *);

int main(int argc, char * argv[]) {
    
    // dichiarazione
    int fl, lf;
    int *ptr_fl, *ptr_lf;
    char seq[DIM+1];
    int max;

    // acquisizione
    printf("inserire stringa: ");
    scanf("%s", seq);

    calibra(seq, &fl, &lf);
    printf("valori: %d %d\n", fl, lf);    

    /* v1
    max = fl ;
    if(*lf > max)
        fl = max;
    printf("valore massimo %d", max);
    */

    // v2
    if((fl - lf) == 0)
        printf("i valori sono uguali");

    else if((fl - lf) < 0) {
        printf("valore massimo %d", lf);
        } else 
            printf("valore massimo %d", fl);

    return 0;
}

void calibra(char *seq, int *ptr_fl, int *ptr_lf) {
    // Scorriamo la stringa
    int first = 0;  
    int last = 0; 
    int flag = 0;

    for(int i = 0; *(seq + i) != '\0'; i++) {
        // Se troviamo un carattere numerico
        if(*(seq + i) >= '0' && *(seq + i) <= '9') {
            //printf("ciclo: %d\n", flag);
            
            // Se è il primo numero che troviamo
            if(flag == 0) {
                first = *(seq + i) - '0';   // Sottrai '0' per ottenere il valore numerico
                //printf("first %d\n", first);
            }
        
            // Aggiorniamo sempre l'ultimo
            last = *(seq + i) - '0';        // Sottrai '0' per ottenere il valore numerico
            flag++;
            
            //printf("last %d\n", last);
        }
    }
    printf("ci sono %d caratteri \n", flag);
    
    // Costruiamo i due valori richiesti
    // primo - ultimo
    *ptr_fl = (BASE * first) + last;

    // ultimo - primo
    *ptr_lf = (BASE * last) + first;
}