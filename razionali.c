 #include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*Realizzare un'applicazione per gestire numeri razionali. L’applicazione deve gestire ciascun numero razionale come una struttura con due campi, che rappresentano numeratore e denominatore del numero razionale.
L’applicazione deve permettere all’utente di svolgere le seguenti funzionalità.
Inserimento di un nuovo numero razionale in testa alla lista.
Cancellazione del numero razionale in fondo alla lista.
Visualizzazione della lista corrente di numeri razionali.
Ordinamento della lista di numeri razionali in base al loro valore.
Riduzione di tutti i numeri razionali della lista ai minimi termini.
All’avvio dell’esecuzione l’applicazione deve inizializzare la lista di numeri razionali con i valori letti da un file; al termine dell’esecuzione l’applicazione deve salvare i dati della lista nello stesso file.
*/
struct razionale{
    int numeratore;
    int denominatore;
};

struct Nodo{
    struct razionale valore;
    struct Nodo* next;
    
};

void inserisciNodo(struct Nodo* head){
printf("inserisi nuovo razionale prima denominatore poi numeratore \n");
struct Nodo* puntanodo;
puntanodo=malloc(sizeof(struct Nodo));
scanf("%d",&(puntanodo->valore.denominatore));
scanf("%d",&(puntanodo->valore.numeratore));
puntanodo->next=head;
head=puntanodo;
}


void cancellaultimo(struct Nodo* head){
    struct Nodo *nodo,*prec;
    nodo=head;
    int s;
    printf("Sei sicuro di voler cancellare l ultimo nodo? \n");
    printf("(1=si.0=no)\n");
    scanf("%d",&s);
    if(s){while(nodo->next->next!=NULL)nodo=nodo->next;
    prec=nodo;
    nodo=nodo->next;
    prec->next=NULL;
    free(nodo);
    printf("l'ultimo nodo è stato cancellato\n");}
else printf("grazie comunque\n");}

void visualizzal(struct Nodo* head){
    struct Nodo* puntanodo;
    puntanodo=head;
    while(puntanodo->next==NULL){
        printf("il numero è %d fratto %d \n",puntanodo->valore.numeratore,puntanodo->valore.denominatore );
    puntanodo=puntanodo->next;}
    
    }
    
    
void ordina(struct Nodo* head){
    struct Nodo* puntanodo;
    struct Nodo* primoordi;
    struct razionale temp;
    if(head->next!=NULL){
    primoordi=head->next;
    while(primoordi->next!=NULL){
    puntanodo=primoordi->next;
    while(puntanodo!=NULL){
     float ordival=(float)((primoordi->valore.numeratore)/(primoordi->valore.denominatore));
     float puntaval=(float)((puntanodo->valore.numeratore)/(puntanodo->valore.denominatore));   
     if(ordival>puntaval){
        temp=primoordi->valore;
        primoordi->valore=puntanodo->valore;
        puntanodo->valore=temp;
    }
    puntanodo=puntanodo->next;
    }
    primoordi=primoordi->next;
    }  
        
    }
    
}

void riduzione(struct Nodo* head){
    
    
    
}    


struct Nodo* leggilista(){
FILE* fp= fopen("razionali","r");
struct Nodo* head = NULL;
struct Nodo* precedente;
struct Nodo* successivo;
struct razionale num;

int letto;
if(fp!=NULL){
    letto= fread(&num,sizeof(struct razionale),1,fp);
    if(letto){ 
        head=malloc(sizeof(struct Nodo));
        head->valore= num;
        precedente=head;
        do{
            letto=fread(&num,sizeof(struct razionale),1,fp);
            if(letto){
                successivo= malloc(sizeof(struct Nodo));
                successivo->valore=num;
                precedente->next=successivo;
                precedente=successivo;
                
        }
        else precedente->next=NULL;
        }while(letto);
    }
}return head;
}

void salvataggio(struct Nodo* head){
    FILE* fp = fopen("razionali","w");
    while(head!=NULL){
        fwrite(&(head->valore),sizeof(struct razionale),1,fp);
        head=head->next;
    }
}

int main(){
    int t;
struct Nodo* head=leggilista();
do{
    printf("inserisci \n 1per ordinare la lista \n 2 per eliminare un elemento in coda \n 3 per eliminare l ultimo valore in coda \n 4 per visualizare la lista \n 5 per salvare la lista \n 9 per chiudere \n");
    scanf("%d",&t);
    if(t==4)visualizzal(head);
    
}while(t!=9);


}
