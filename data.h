#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LUN 20
#define MAX 10
#define DIM 5
#define DAY 31
#define HOUR 3
#define NMAX 50

typedef int bool;
#define false 0
#define true 1
typedef int bool;
#define false 0
#define true 1

//Struct prenotazione

struct data{

    int giorno;
    char mese;
    int ora;
    int n_partecipanti;
    int id_tavolo;
    char nome[LUN];
    char cognome[LUN];
    char contatto[MAX];
    bool pizza;


};
typedef struct data tdata;

struct nodo{

    tdata info;
    struct nodo *next;

};
typedef struct nodo prenotazione;

//Struct Sala

struct informazioni{

    char tipo_sala[DIM];
    int n_tavoli[NMAX];
    int id_tavolo[NMAX];
    int n_posti;
    int t_disponibili;
    int t_occupati;

};
typedef struct informazioni tinfo;

struct node{

    tinfo dati;
    struct node *next;

};
typedef struct node sale;


//Struct calendario

struct elementi{

    char mese[MAX];
    char giorno[DAY];
    char fascia_oraria[HOUR];
    bool apertura;

};

typedef struct elementi telementi;

struct membro{

    telementi date;
    struct membro *next;

};

typedef struct membro calendario;

//prototipi di funzioni

prenotazione *inizializza_p(char *, prenotazione *);
calendario *inizializza_c(char *, calendario*);
prenotazione *inserisci_prenotazione(prenotazione *);
prenotazione *inserisci_da_file(char *, prenotazione *);
void disponibili(sale *, calendario *);