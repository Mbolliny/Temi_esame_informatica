/*
In relazione ad alcuni esperimenti, si utilizzano file ASCII contenenti sequenze alfanumeriche, una per riga, ognuna di al più 1000 caratteri. 
Si sta cercando il file che contiene meno sequenze (quindi meno righe) per poterlo utilizzare. 

Scrivere un sottoprogramma che ricevuta in ingresso una lista di nomi di file restituisce al chiamante il riferimento al nome del file che si sta cercando. 

É utile realizzare un sottoprogramma che ricevuto in ingresso il nome di un file restituisce il numero di sequenze (ossia righe) in esso contenute. 
Nel caso in cui si verifichino problemi di accesso ad un file della lista, lo si ignori (ma si non si vada in errore). 
 
Il tipo di dato per la lista che il sottoprogramma riceve in ingresso è il seguente:
typedef struct _slist{
       char * nomefile;
       struct _slist * next;
} slist_t;
*/

#include <stdio.h>

typedef struct _slist{
   char * nomefile;
   struct _slist *next;
} slist_t;

int main(int argv, char * argv[]) {
   
   slist_t *head = NULL;
   slist_t *ptr = head;  // ptr ora punta allo stesso nodo di head
   int result;
   FILE * shortest;

   // Aggiunta dei file alla lista
   head = append(head, "/Users/matteo/Library/Mobile Documents/com~apple~CloudDocs/Anno1/informatica/temi_esame/20240213/q5/file5.txt");
   head = append(head, "/Users/matteo/Library/Mobile Documents/com~apple~CloudDocs/Anno1/informatica/temi_esame/20240213/q5/file4.txt");
   head = append(head, "/Users/matteo/Library/Mobile Documents/com~apple~CloudDocs/Anno1/informatica/temi_esame/20240213/q5/file3.txt");
   head = append(head, "/Users/matteo/Library/Mobile Documents/com~apple~CloudDocs/Anno1/informatica/temi_esame/20240213/q5/file2.txt");
   head = append(head, "/Users/matteo/Library/Mobile Documents/com~apple~CloudDocs/Anno1/informatica/temi_esame/20240213/q5/file1.txt");

   // Stampa della lista per controllo
   stampaLista(head);

   result = shortestfile(head, &shortest)

   return 0;
}

// Funzione calcolo minore
int shortestfile(slist_t *head, FILE * shortest) {

   FILE * fin;
   int nrighe;
   int max = 0;
   char buffer[1000+1]
   
   // scorro ogni membro della lista
   for(ptr = head; ptr->next != NULL; ptr = ptr->next)

      //apro file
      if(fin = fopen(ptr->nomefile, "r") != NULL) {

         // ripristino condizioni
         nrighe = 0;

         // Passo tutte le righe disponibili
         while (fgets(buffer, LENGHT + 1, fin)) {
            nrighe++;
         
         /* chiusura file */
         fclose(fin);

      if(nrighe > max) {
         max = nrighe; // numero righe
         *shortest = ptr->nomefile; // nome file
      }
      
      } else printf("problemi accesso file %s\n", ptr->nomefile);
         
   return max;
}

// Funzione per aggiungere un nodo alla lista
slist_t *aggiungiNodo(slist_t *head, char *nomefile) {
    slist_t *nuovo = malloc(sizeof(slist_t));
    if (!nuovo) {
        printf("Errore allocazione memoria\n");
        return head;
    }
    nuovo->nomefile = nomefile;
    nuovo->next = head;
    return nuovo;
}

// Funzione per stampare la lista (debug)
void stampaLista(slist_t *head) {
    slist_t *ptr = head;
    while (ptr) {
        printf("%s -> ", ptr->nomefile);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

