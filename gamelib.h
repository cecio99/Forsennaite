#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <string.h>

#include <unistd.h>

#define COL(x) "\033[" #x ";1m" 
#define ROSSO COL(31)
#define VERDE COL(32)
#define GIALLO COL(33)
#define BLU COL(34)
#define BIANCO COL(37)
#define GRIGIO "\033[0m"



#define pulizia system ("clear")

#define prob rand () %101

//int num_celle=0;

enum Stato_giocatore {vulnerabile, scudo_vita, solo_vita, solo_scudo, morto}; //possibili stati di vita del giocatore

enum Tipo_pericolo {nessun_pericolo, trappola, alieno}; //tipi di pericoli che i giocatori possono incontrare

enum Tipo_oggetto {nessun_oggetto, medikit, pozione, materiale, colpi_lanciarazzi}; //tipi di oggetti che i giocatori possono incontrare

struct Giocatore {
    enum Stato_giocatore stato;
    int x;                          //posizione x schacchiera
    int y;                         //posizione y scacchiera
    int zaino [4];                //array zaino con 4 oggetti
    int alieni_uccisi;          //numero di alieni uccisi
    int turno_G;
    struct Piano *Torre;
    struct Piano *Ultimo_piano;
};

struct Cella {
    enum Tipo_pericolo pericolo;
    enum Tipo_oggetto oggetto;
};

struct Piano{                       //struct per la battaglia finale
    unsigned short int n_piano;            
    struct Piano *ProssimoPiano;
};

typedef struct Piano P_N;

void menu ();

void crea_mappa ();

void crea_scacchiera ();

void stampa_scacchiera ();

void termina_scacchiera ();

void gioca ();

void termina_gioco ();

void muovi ();

void usa_oggetto ();

void funcalieno ();

void functrappola ();

void stampastato();

void stampazaino();

void nuova_partita();

void restri_mappa();

void round_finale();

void aggiungi_piano();

void elimina_piano();

void stampa_diagonale();