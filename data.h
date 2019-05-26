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

//Struct prenotazione

struct data{

    int giorno;
    char mese;
    int ora;
    int n_partecipanti;
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
    int n_tavoli;
    int t_disponibili;
    int t_occupati;

};
typedef struct informazioni informazioni;
typedef informazioni * sala;



//struct tavoli

struct caratteristiche{

    int id_tavolo;
    int nposti;
};
typedef struct caratteristiche caratteristiche;
typedef caratteristiche * tavolo


//Struct calendario

struct elementi{

    char mese[MAX];
    char giorno[DAY];
    char fascia_oraria[HOUR];
    bool apertura;
    int pieno;

};

typedef struct elementi elementi;
typedef elementi * giorni;



//prototipi di funzioni

prenotazione *inizializza_p(char *, prenotazione *);
giorni inizializza_c(int);
void carica_c(char *, giorni);
sala inizializza_s(int);
void carica_s(sala);
tavolo inizializza_t(int);
void carica_t(tavolo);
prenotazione *inserisci_prenotazione(prenotazione *);
prenotazione *inserisci_da_file(char *, prenotazione *);
void disponibili(sale *, calendario *);

