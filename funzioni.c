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
 * - char *nomefile: un puntatore al nome del file che conterrà le un calendario con orari di apertura e chiusura, i giorni del mese e una una variabile 1 oppure 0 (variabile booleana che
 *   sta a signigicare 1 che il ristorante in quel giorno è aperto, 0 che invece è chiuso
 * - prenotazione *p: un puntatore alla struttura
 *
 *  restituisce una variabile di tipo calendario che conterrà i giorni di apertura e chiusura del mese corrente con i rispettivi orari di apertura e chiusura
 *
 */

    calendario* inizializza_c(char *nomefile2, calendario *p){
        telementi elemento;
        calendario *nuovo;
        FILE *fp;

            if (fp=fopen(nomefile2, "r")!=NULL){
                while(fscanf(fp,"%s%s%d%d%[^\n]\n", elemento.mese, elemento.giorno, elemento.fascia_oraria, elemento.apertura) !=EOF){
                    nuovo=(calendario*) malloc (sizeof(calendario));
                    nuovo->date = elemento;
                    nuovo->next = p;
                    p = nuovo;
                }

            }else{
                printf("Errore nell'apertura del file.\n");
            }
            fclose(fp);
        return p;
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







/*
* - prenotazione *p: un puntatore alla struttura
*
*
*
*
* - restituisce una variabile di tipo prenotazione che conterrà la lista
*
*/


