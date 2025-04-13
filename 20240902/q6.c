#include <stdio.h>
#include <stdlib.h> // Aggiungi questa libreria per malloc e free

/* define */
#define STOP 0
#define TRUE 1
#define FALSE 0

/* testa */
typedef struct ilista_s {
    int val; /* campo (informazione) */
    struct ilista_s *next; /* indirizzo */
} ilista_t;

/* prototipi */
ilista_t* aggiungo(ilista_t *, int);
void stampa_lista(ilista_t *);
void libera_memoria(ilista_t *head);

int main(int argc, char *argv[]) {  // Correzione: 'int main'
    ilista_t *head = NULL;  // Testa della lista
    int num, trovato;
    ilista_t *ptr; // Aggiunta dichiarazione di ptr

    // Chiedo numero la prima volta
    printf("Inserisci un numero (0 per terminare): ");
    scanf("%d", &num);

    // Se il numero non è un terminatore, lavoro
    while (num != STOP) {
        
        // ripristino condizioni iniziali
        ptr = head; // parto dall'inizio della lista
        trovato = FALSE;

        // Scorro la lista fino all'ultimo nodo
        if (ptr != NULL) {
            for(ptr = head; ptr->next != NULL; ptr = ptr->next) { 
                // verifica che il numero sia presente
                if (ptr->val == num) {
                    trovato = TRUE;
                }
            }
        }

        // se elemento non è stato trovato in lista -> aggiungo in fondo
        if (trovato == FALSE) {
            if (head == NULL) {
                head = aggiungo(head, num); // Se la lista è vuota, head è aggiornata
            } else {
                ptr->next = aggiungo(ptr, num); // Altrimenti aggiungo alla fine
            }
        }

        // Chiedo un nuovo numero
        printf("Inserisci un numero (0 per terminare): ");
        scanf("%d", &num);
    }

    // Dopo che il ciclo di inserimento è terminato
    stampa_lista(head);  // Stampa la lista

    // Liberazione della memoria con il sottoprogramma
    libera_memoria(head);

    return 0; // Correzione: aggiungi il return 0 per main
}   

ilista_t* aggiungo(ilista_t *ptr, int num) {
    ilista_t *elem; // definisco nuova cella
    elem = (ilista_t *) malloc(sizeof(ilista_t)); // alloco spazio per elem

    if (elem) { // se allocazione va a buon fine posso lavorare
        elem->val = num; // 2. Imposto il valore del nuovo nodo
        elem->next = NULL; // 3. L'elemento sarà l'ultimo, quindi next è NULL
        if (ptr != NULL) {
            ptr->next = elem; // 4. Collego ptr al nuovo nodo
        }
    } else {
        printf("append: errore allocazione %d\n", num); // errore con num
    }

    return elem;  // Restituisci il nuovo nodo
}

void stampa_lista(ilista_t *head) {
    ilista_t *ptr = head;  // Iniziamo dalla testa della lista
    while (ptr != NULL) {  // Continua finché non raggiungi la fine della lista
        printf("%d ", ptr->val);  // Stampa il valore del nodo
        ptr = ptr->next;  // Vai al nodo successivo
    }
    printf("\n");  // Aggiungi una nuova linea alla fine
}

void libera_memoria(ilista_t *head) {
    ilista_t *ptr = head;
    while (ptr != NULL) {
        ilista_t *temp = ptr;
        ptr = ptr->next;
        free(temp);  // Libera la memoria
    }
}

