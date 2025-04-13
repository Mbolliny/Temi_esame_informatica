/*
Scrivere un programma che riceve da riga di comando i nomi di due file ASCII, 
rispettivamente il file sorgente e il file destinazione. 
Il programma, se il file sorgente esiste, crea il file destinazione riportando 
tutte le righe del file sorgente che non siano vuote. 
Una riga si definisce vuota se contiene solo il carattere "a capo" ed al più spazi. 
Le righe del file contengono al più 80 caratteri.
*/

#include <stdio.h>
//#include <stdlib.h> // se lavoro con liste 

/* define */
#define LENGHT 80
#define SORGENTE "/Users/matteo/Library/Mobile Documents/com~apple~CloudDocs/Anno1/informatica/temi_esame/20240902/q5_sorgente.txt"
#define DESTINAZIONE "/Users/matteo/Library/Mobile Documents/com~apple~CloudDocs/Anno1/informatica/temi_esame/20240902/q5_destinazione.txt"

int main (int argc, char * argv [])
{
	/* dichiarazione */
	char sorgente[LENGHT+1], destinazione[LENGHT+1], buffer[LENGHT+1]; // stringhe
	FILE * fin1, * fin2; // file
	int i, carin;

	/* acquisizione 
	printf("inserire nome file SORGENTE: ");
	scanf("%s", sorgente);

	printf("inserire nome file DESTINAZIONE: ");
	scanf("%s", destinazione);
	*/

    /* operazioni */
    if ((fin1 = fopen(SORGENTE, "r")) != NULL) {
        if ((fin2 = fopen(DESTINAZIONE, "w")) != NULL) {

            // Passo tutte le righe disponibili in file SORGENTE
            while (fgets(buffer, LENGHT + 1, fin1)) {
                carin = 0;  // Inizializzo la variabile carin per ogni riga

                // Scorro la stringa (riga)
                for (i = 0; buffer[i] != '\0'; i++) {

                    // Rilevo eventuali caratteri che non siano \n o spazi
                    if (buffer[i] != '\n' && buffer[i] != ' ') {
                        carin++;  // Incremento il contatore se il carattere è valido
                    }
                }

                // Se la riga non è vuota (carin != 0), stampo nel file destinazione
                if (carin != 0) {
                    fprintf(fin2, "%s", buffer);  // Scrivo la riga nel file destinazione
                    printf("%s", buffer);
                }
            }

            fclose(fin2);
        } else {
            printf("Problema accesso al file '%s' in scrittura.\n", DESTINAZIONE);
        }

        fclose(fin1);
    } else {
        printf("Problema accesso al file '%s' in lettura.\n", SORGENTE);
    }

    return 0;
}