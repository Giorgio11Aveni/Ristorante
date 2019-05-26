#include "data.h"

/*
 * Funzione: inizializza_p
 *
 * - char *nomefile: un puntatore al nome del file che conterrà le prenotazioni
 * - prenotazione *p: un puntatore alla struttura
 *
 *  restituisce una variabile di tipo prenotazioni che conterrà tutte le prenotazioni
 *
 */

prenotazione *inizializza_p(char *nomefile, prenotazione *p){
    tdata elem;
    prenotazione *newElem;
    FILE *fp;

            if((fp=fopen(nomefile, "r"))!=NULL){
                while(fscanf(fp,"%d%c%d%d%d%s%s%s%[^\n]\n" , elem.giorno, elem.mese, elem.ora, elem.n_partecipanti, elem.id_tavolo, elem.nome, elem.cognome, elem.contatto, elem.pizza)!=EOF){
                    newElem = (prenotazione*) malloc (sizeof(prenotazione));
                    newElem->info = elem;
                    newElem->next = p;
                    p = newElem;
                    }
                }else{
                    printf("Errore nell'apertura del file.");
            }
            fclose(fp);
        return p;
    }


/*
 * Funzione: inizializza_c
 *
 * - giorni del mese
 *
 *
 *  restituisce una variabile di tipo giorni che conterrà il calendario mensile
 *
 */



giorni inizializza_c(int giorni){

giorni calendario;
int i;

    calendario = (giorni) malloc (sizeof(elementi));

    for (i=0;i<DAY;i++){
    calendario[i].pieno = 0;

    }

    return calendario;
}




  /*
 * Funzione: carica_c
 *
 * - char *nomefile: un puntatore al nome del file che conterrà le un calendario con orari di apertura e chiusura, i giorni del mese e una un valore che sarà 1 o 0 (variabile booleana che
 *   sta a signigicare 1 che il ristorante in quel giorno è aperto, 0 che invece è chiuso
 *
 * - giorni calendario: variabile che conterrà il calendario
 *
 *  carica gli i giorni del mese corrente con rispettivi orari di apertuera del ristorante dentro la variabile calendario
 *
 */

    void carica_c(char *nomefile2, giorni calendario){

        FILE *fp;
        int i=0;


                if (fp=fopen(nomefile2, "r")!=NULL){
                    while(!feof(fp)){
                        fscanf(fp,"\n%[^\n]", calendario[i].mese);
                        if(!feof(fp)){
                        fscanf(fp,"%d%d%d%[^\n]", calendario[i].giorno, calendario[i].fascia_oraria, calendario[i].apertura);
                        calendario[i].pieno = 1;
                        i++;
                    }else{
                        break;
                    }

                    }
                }else{
                    printf("Errore nell'apertura del file.\n");
            }
            fclose(fp);
        return calendario;
}




/*
* - prenotazione *p: un puntatore alla struttura
*
*
*
*
* - restituisce una variabile di tipo prenotazione che conterrà la lista
*
*/

void disponibili(sale *p, calendario *p2){
    int cont=0;
    for (int i=0;i<NMAX;i++){
        if (p->dati.id_tavolo==NMAX){
            printf("La sala è piena.");
            for (int i=0;i<NMAX;i++){
                if (p->dati.id_tavolo[i]>cont){
                    p->dati.t_occupati++;
                    p->dati.t_disponibili--;
                    cont++;
                    p=p->next;
                }
                printf(p->dati.t_disponibili);
                }
                }
                    if (p->dati.t_disponibili==0){
                        printf("La sala è piena.");
                    }else{
                        printf("%d%s%d",p2->date.giorno, p2->date.mese, p2->date.fascia_oraria, "Disponibili: %d",p->dati.t_disponibili);
                    }

                }
            }




tavoli *inizializza_tavoli(tavoli *p){
tavoli tavoli_sale[NMAX];











    }

}



/*
* - prenotazione *p: un puntatore alla struttura prenotazioni
* - sale *p2: un puntatore alla struttura sale
*
*
*
* - Controlla la disponibilità dei tavoli, crea un nuovo nodo e ne inserisce all'interno i campi che vengono inseriti dall'utente
*
*/

prenotazione *inserisci_prenotazione(prenotazione *p, sale *p2){

    int giorno;
    char mese;
    int ora;
    int n_partecipanti;
    char nome[LUN];
    char cognome[LUN];
    char contatto[MAX];
    bool pizza;
    tdata da_agg;
    prenotazione *p3 = NULL;

    if (p2->dati.t_disponibili == 0){
        printf("Impossibile prenotarsi, il ristorante è pieno");
    }else{

        printf("Inserisci i dati della prenotazione.\n");

        printf("Inserisci il giorno.\n");
        scanf("\n%[^\n]",&giorno);
        strcpy(da_agg.giorno, giorno);

        printf("Inserisci il mese.\n");
        scanf("n\%[^\n]", mese);
        strcpy(da_agg.mese, mese);

        printf("Inserisci l'orario.\n");
        scanf("\n%[^\n]", &ora);
        strcpy(da_agg.ora, ora);

        printf("Inserisci il numero di partecipanti.\n");
        scanf("\n%[^\n]", n_partecipanti);
        strcpy(da_agg.n_partecipanti, n_partecipanti);

        printf("Inserisci il nome di chi sta effettuando la prenotazione.\n");
        scanf("\n%[^\n]", nome);
        strcpy(da_agg.nome, nome);

        printf("Inserisci il cognome di chi sta effettuando la prenotazione.\n");
        scanf("\n%[^\n]", cognome);
        strcpy(da_agg.cognome, cognome);

        printf("Inserisci il contatto di chi sta effettuando la prenotazione.\n");
        scanf("\n%[^\n]", contatto);
        strcpy(da_agg.contatto, contatto);

        printf("Inserisci il tipo di pasto.\n");
        scanf("\n%[^\n]", pizza);
        strcpy(da_agg.pizza, pizza);

        if(p!=NULL){

        p3 = (prenotazione*)malloc(sizeof(prenotazione));
        p3->info = da_agg;
        p3->next=p;

        }else{

            p=(prenotazione*)malloc(sizeof(prenotazione));
            p->next=NULL;
            p2=p;
        }
        return p2;
    }

}


