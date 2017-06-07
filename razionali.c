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
    while(puntanodo !=NULL){
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
FILE* fp= fopen("razionali.txt","r");
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
    
}fclose(fp);

return head;
}

void salvataggio(struct Nodo* head){
    FILE* fp = fopen("razionali.txt","w");
    while(head!=NULL){
        fwrite(&(head->valore),sizeof(struct razionale),1,fp);
        head=head->next;
    }fclose(fp);
}

int main(){
    int t;

struct Nodo* head=leggilistatastiera();
do{
    printf("inserisci \n 1per ordinare la lista  \n 2 per eliminare l ultimo valore in coda \n 3 per visualizare la lista \n 4per salvare la lista \n 9 per chiudere \n");
    scanf("%d",&t);
    if(t==1)ordina(head);
    if(t==2)cancellaultimo(head);
    if(t==3)visualizzal(head);
    if(t==4)salvataggio(head);
}while(t!=9);


}
