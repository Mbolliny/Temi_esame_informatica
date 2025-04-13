#include <stdio.h>
#include <stdlib.h> // Aggiungi questa libreria per malloc e free

/* define */
#define STOP 0
#define TRUE 1
#define FALSE 0

// definizione della testa
typedef struct ilista_s {
	int val;
	int * next;
}	ilista_t;

main(int argv, char * argv[]) {

	// definzione della testa
	ilista_s * head = NULL;
	ilista * ptr;

	// inizializzazione
	int trovato;
	int num;

	if(head) {

		do { 
			
			// acquisisco primo valore
			printf("Inserisci un numero (0 per terminare): ");
		    scanf("%d", &num);

		    if(num != STOP) {

		    	// ripristino condizioni
			    ptr = head;
			    trovato = FALSE;
			    	
			    // scorrere lista
			    for(ptr = head; ptr->next != NULL; ptr = ptr->next)
			    	// verificare che la lista non contenga già quel numero
			    	if(ptr->val == num);
			    			trovato = TRUE;
			    	
				// se non è presente -> aggiungo in fondo
			    if(trovato == FALSE)
			    		ptr = append(ptr, num);
		    }

		} while(num != STOP)

	    // stampa
	    print_list(head);

	    // libero la memoria
	    free_list(head);

	} else printf("errore allcazione spazio per la testa")

	return 0;
}

ilista * append(ilista_t *ptr,int num){

	ilista * elem;

	//allocazione spazio nuova cella
	elem = (ilista_t *) malloc(sizeof(ilista_t));

	if(elem != NULL) {
		
		elem->val = num; //riempio cella val
		elem->next = NULL; //colego ptr a elem
		ptr->next = elem;

	} else printf("errore allcazione spazio elem")

	return elem;

}

void print_list(ilista_t *head) {

	for(ptr = head; ptr->next != NULL; ptr = ptr->next);
		printf("%d ", ptr->val);  // Stampa il valore del nodo
}

void free_list(ilista_t *ptr) {

	ilista * elem;

	//allocazione spazio nuova cella
	elem = (ilista_t *) malloc(sizeof(ilista_t));
	
	for(ptr = head; ptr->next != NULL; ptr = ptr->next);
		ptr->next = elem->next;

}
