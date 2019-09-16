#include "gamelib.h"

static int nex_ogg, mdk, poz, mat, razzi, nex_per, ali, trap, somma_pericoli, somma_oggetti;

static int num_celle;

unsigned int turno;

struct Cella *scacchiera=NULL;

static struct Giocatore Ninja;

static struct Giocatore Ciccio;

static struct Giocatore *Player=NULL;
 
void menu (){
    pulizia;
    printf("%s", VERDE);
    printf("\n\n\n");
printf("███████╗ ██████╗ ██████╗ ███████╗███████╗███╗   ██╗███╗   ██╗ █████╗ ██╗████████╗\n");
printf("██╔════╝██╔═══██╗██╔══██╗██╔════╝██╔════╝████╗  ██║████╗  ██║██╔══██╗██║╚══██╔══╝\n");
printf("█████╗  ██║   ██║██████╔╝███████╗█████╗  ██╔██╗ ██║██╔██╗ ██║███████║██║   ██║ \n");  
printf("██╔══╝  ██║   ██║██╔══██╗╚════██║██╔══╝  ██║╚██╗██║██║╚██╗██║██╔══██║██║   ██║ \n");
printf("██║     ╚██████╔╝██║  ██║███████║███████╗██║ ╚████║██║ ╚████║██║  ██║██║   ██║   \n");
printf("╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═══╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝   ╚═╝   \n\n\n\n");
printf("%s", BIANCO);
int inizio;
do{
printf("\n Benvenutooo!!\n Digita [1] per creare la mappa, [2] per iniziare a giocare, [3] per uscire.\n [1] Crea mappa. \n [2] Gioca.\n [3] Esci.\n --->");
scanf("%d", &inizio);
/*if(inizio!=1 && inizio!=2 && inizio!=3){
   printf("%s", ROSSO);
   printf("\n ERRORE!! Digita un numero da 1 a 3\n\n" "%s", BIANCO);
   sleep(2);
    pulizia;*/
//x}
}while(inizio !=1 && inizio!=2 && inizio!=3);
switch(inizio){
    case 1: crea_mappa();
    break;
    case 2: if(scacchiera==NULL){
               printf("%s", ROSSO);
               printf("\n Non puoi giocare finchè non crei la mappa!!" "%s", BIANCO);
            }
            else{
                pulizia;
                 gioca();
            }
    break;
    case 3: termina_gioco();
}
}                                                       

void crea_mappa (){
    pulizia;

       printf("%s",ROSSO);       
printf("▄████▄   ██▀███  ▓█████ ▄▄▄          ███▄ ▄███▓ ▄▄▄       ██▓███   ██▓███   ▄▄▄ \n");    
printf("▒██▀ ▀█  ▓██ ▒ ██▒▓█   ▀▒████▄       ▓██▒▀█▀ ██▒▒████▄    ▓██░  ██▒▓██░  ██▒▒████▄ \n");   
printf("▒▓█    ▄ ▓██ ░▄█ ▒▒███  ▒██  ▀█▄     ▓██    ▓██░▒██  ▀█▄  ▓██░ ██▓▒▓██░ ██▓▒▒██  ▀█▄\n");  
printf("▒▓▓▄ ▄██▒▒██▀▀█▄  ▒▓█  ▄░██▄▄▄▄██    ▒██    ▒██ ░██▄▄▄▄██ ▒██▄█▓▒ ▒▒██▄█▓▒ ▒░██▄▄▄▄██ \n");
printf("▒ ▓███▀ ░░██▓ ▒██▒░▒████▒▓█   ▓██▒   ▒██▒   ░██▒ ▓█   ▓██▒▒██▒ ░  ░▒██▒ ░  ░ ▓█   ▓██▒\n");
printf("░ ░▒ ▒  ░░ ▒▓ ░▒▓░░░ ▒░ ░▒▒   ▓▒█░   ░ ▒░   ░  ░ ▒▒   ▓▒█░▒▓▒░ ░  ░▒▓▒░ ░  ░ ▒▒   ▓▒█░\n");
printf("░  ▒     ░▒ ░ ▒░ ░ ░  ░ ▒   ▒▒ ░   ░  ░      ░  ▒   ▒▒ ░░▒ ░     ░▒ ░       ▒   ▒▒ ░\n");
printf("░          ░░   ░    ░    ░   ▒      ░      ░     ░   ▒   ░░       ░░         ░   ▒\n");   
printf("░ ░         ░        ░  ░     ░  ░          ░         ░  ░                        ░  ░\n");
printf("░");                                                                                               
printf("%s", BIANCO);

    int n_map;
    do{
        printf("\n Inserisci 1 per accedere a Crea mappa. \n Inserisci 2 per accedere a Visualizza mappa. \n Inserisci 3 per accedere a Termina mappa.\n");
        printf("\n [1] Crea mappa. \n [2] Visualizza mappa. \n [3] Termina mappa.\n [4] Trappole e alieni nella diagonale. \n --->");
        scanf("%d", &n_map);
        if(n_map !=1 && n_map !=2 && n_map !=3 && n_map!=4){
            printf("%s", ROSSO);
            printf("\n\n ERRORE!! Digita un numero da 1 a 4\n\n" "%s", BIANCO);
            sleep(1);
           pulizia;  
        }        
    }while(n_map !=1 && n_map !=2 && n_map !=3 && n_map !=4);
            pulizia;
    switch(n_map){
        case 1: crea_scacchiera();
        break;
        case 2: stampa_scacchiera();
        break;
        case 3: termina_scacchiera();
        break;
        case 4: stampa_diagonale();
        break;
    }
} 

void gioca(){
    int go;
    _Bool fine=0;
    do{
        go=0;
        pulizia;
                
        if(turno%2==0){
                    Player=&Ciccio;
                     printf("\n ****************");
                    printf("\n E\' il turno di Ciccio!");
                    printf("\n E\' il turno numero: %d",Player->turno_G+1);
                    stampastato();
                    stampazaino();
                    printf("Il numero di alieni uccisi e\': %d", Ciccio.alieni_uccisi);
                    printf("\n");
                  
                }
                else{
                    Player=&Ninja;
                    printf("\n ****************");
                    printf("\n E\' il turno di Ninja!");
                     printf("\n E\' il turno numero: %d",Player->turno_G+1);
                    stampastato();
                    stampazaino();
                    printf("Il numero di alieni uccisi e\': %d", Ninja.alieni_uccisi);
                    printf("\n");
                  
                }
                if(Player->turno_G!=0 && (num_celle/Player->turno_G)==2){
                    restri_mappa();
                }
                if(Ninja.stato!=morto && Ciccio.stato!=morto){
                 do{
                    printf("\n Inserisci 1 per muoverti;\n 2 per usare un oggetto;\n 3 per terminare il gioco;\n 4 per visualizzare la mappa!\n");
                    scanf("%d",&go);
                 }while(go<1 && go>3);
                }

    switch (go){
        case 1: muovi();
                break;
        case 2: usa_oggetto();
                break;
        case 3: termina_gioco();
                break;
        case 4: for (int i=0; i<num_celle; i++){
            for (int j=0; j<num_celle; j++){
            
               
                if(Ciccio.y==i && Ciccio.x==j) printf ("Ciccio");
                else{
                    if (Ninja.y==i && Ninja.x==j) printf (" Ninja");
                 else{
                 printf(" [%d %d]", i, j);
                 }
                }
            }
            printf("\n");
        }
       int stop;
    do{
        printf("\n\nClicca 1 per andare avanti!! ");
        scanf("%d",&stop);
    }while(stop!=1);
                break;
    }
    
        if (Ciccio.x==Ninja.x && Ciccio.y==Ninja.y){
            fine=1;
        }
    
    }while(Ninja.stato!=morto && Ciccio.stato!=morto && fine==0);

    if(fine && Ninja.stato!=morto && Ciccio.stato!=morto){
        round_finale();
    }
    if(Ninja.stato==morto && Ciccio.stato==morto){
        printf("\n Entrambi i giocatori sono morti!!");
    }
    if(Ninja.stato==morto && Ciccio.stato!=morto){
        printf("\n Ninja e\' MORTO!! \n IL VINCITORE E\' CICCIO");
        nuova_partita();
    }
    if(Ciccio.stato==morto && Ninja.stato!=morto){
        printf("\n Ciccio e\' MORTO!! \n IL VINCITORE E\' NINJA");
        nuova_partita();
    }
    nuova_partita();
}

void crea_scacchiera (){
    
    do{
    printf("\n inserisci la grandezza della mappa (n*n)\n   ");
    scanf("%d", &num_celle);
    if(num_celle<1) printf("\n ERRORE!! \t Inserisci un numero maggiore di zero!\n");
    }while(num_celle<1);
    
     do {
        printf("\n inserisci la probabilità in percentuale di trovare nessun pericolo:      ");
        scanf ("%d", &nex_per);
        printf("\n inserisci la probabilità di trovare un alieno:       ");
        scanf ("%d", &ali);
        printf("\n inserisci la probabilità di trovare una trappola:        ");
        scanf("%d", &trap);
        somma_pericoli = nex_per + ali + trap;
        if (somma_pericoli !=100){
             pulizia;
             printf("\n la somma delle probabilità deve essere uguale a 100\n");
             }
       } while(somma_pericoli != 100);

    pulizia;
   
    puts("BEN FATTO! PROSEGUIAMO");

    do {
        printf("\n inserisci la probabilità in percentuale di non trovare alcun oggetto:     ");
        scanf("%d", &nex_ogg);
        printf("\n inserisci la probabilità in percentuale di trovare medikit:      ");
        scanf("%d", &mdk);
        printf("\n inserisci la probabilità in percentuale di trovare pozioni:     ");
        scanf("%d", &poz);
        printf("\n inserisci la probabilità in percentuale di trovare materiali:    ");
        scanf("%d", &mat);
        printf("\n inserisci la probabilità in percentuale di trovare colpi per il lanciarazzi:     ");
        scanf("%d", &razzi);
        somma_oggetti = nex_ogg + mdk + poz + mat + razzi;
        if(somma_oggetti != 100){
            pulizia;
            printf("\n la somma delle probabilità deve essere uguale a 100\n");
        }
    } while (somma_oggetti != 100);

    pulizia;
    
    scacchiera=malloc(num_celle*num_celle*sizeof(struct Cella));
    
    for(int i=0; i<num_celle; i++){
        for(int j=0; j<num_celle; j++){
            
            if(prob<=nex_per)  scacchiera[i*num_celle+j].pericolo= nessun_pericolo;
            else {
                if(prob<=nex_per+ali) scacchiera[i*num_celle+j].pericolo= alieno;     
                else{
                    if(prob<=nex_per+ali+trap) scacchiera[i*num_celle+j].pericolo= trappola;
                }         
            }               
            if(prob<=nex_ogg) scacchiera[i*num_celle+j].oggetto= nessun_oggetto;
            else{
                if(prob<=nex_ogg+mdk) scacchiera[i*num_celle+j].oggetto= medikit;
                else{
                    if(prob<=nex_ogg+mdk+poz) scacchiera[i*num_celle+j].oggetto= pozione;
                    else{
                        if(prob<=nex_ogg+mdk+poz+mat) scacchiera[i*num_celle+j].oggetto= materiale;
                        else{
                            if(prob<=nex_ogg+mdk+poz+mat+razzi) scacchiera[i*num_celle+j].oggetto= colpi_lanciarazzi;
                        }
                    }
                }
            }
              
        }
    }
    do{
    Ciccio.x= rand () % num_celle;
    Ciccio.y= rand () % num_celle;
    Ninja.x= rand () % num_celle;
    Ninja.y=rand () % num_celle;
    Ciccio.stato= solo_vita;
    Ninja.stato= solo_vita;
    Ciccio.alieni_uccisi=0;
    Ninja.alieni_uccisi=0;
    Ciccio.turno_G=0;
    Ninja.turno_G=0;
    for(int z=0; z<4; z++){
        Ciccio.zaino[z]=nessun_oggetto;
    }
    for(int z=0; z<4; z++){
        Ninja.zaino[z]=nessun_oggetto;
    }
    }while(Ciccio.x==Ninja.x && Ciccio.y==Ninja.y);
    pulizia;

    printf("Ben fattoo!!\n");
    sleep(1);
    crea_mappa();
 }




void stampa_scacchiera (){
    if (scacchiera==NULL) {
        printf("\n ERRORE!! \n NON HAI ANCORA CREATO LA MAPPA");
        crea_scacchiera();
        }
        pulizia;

        printf("\n\n");
        printf("%s", ROSSO);
printf(" ▄▄       ▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄\n"); 
printf("▐░░▌     ▐░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌\n");
printf("▐░▌░▌   ▐░▐░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌\n");
printf("▐░▌▐░▌ ▐░▌▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌\n");
printf("▐░▌ ▐░▐░▌ ▐░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌\n");
printf("▐░▌  ▐░▌  ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌\n");
printf("▐░▌   ▀   ▐░▌▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌\n");
printf("▐░▌       ▐░▌▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌\n");
printf("▐░▌       ▐░▌▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌\n");
printf("▐░▌       ▐░▌▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌\n");
printf(" ▀         ▀  ▀         ▀  ▀            ▀            ▀         ▀ \n\n\n");     
printf("%s", BIANCO);                        
        for (int i=0; i<num_celle; i++){
            for (int j=0; j<num_celle; j++){
                if(i==j){
                if(scacchiera[i*num_celle+j].pericolo==trappola || scacchiera[i*num_celle+j].pericolo==alieno){
                if(scacchiera[i*num_celle+j].pericolo==trappola) printf("trappo");
                if(scacchiera[i*num_celle+j].pericolo==alieno) printf("alieno");}
                }

               
                if(Ciccio.y==i && Ciccio.x==j) printf ("Ciccio");
                else{
                    if (Ninja.y==i && Ninja.x==j) printf (" Ninja");
                 else{
                 printf(" [%d %d]", i, j);
                 }
                }
            }
            
            printf("\n");
            
        }
       int stop;
    do{
        printf("\n\nClicca 1 per andare avanti!! ");
        scanf("%d",&stop);
    }while(stop!=1);
    
        
        crea_mappa();

}

void termina_scacchiera (){
    if (scacchiera==NULL) {
        printf("\n ERRORE!! \n NON HAI ANCORA CREATO LA MAPPA");
        crea_scacchiera();
    }
    menu();
}

void muovi (){
    
    int sposta;
    enum Tipo_oggetto appoggio_1;

        do{
        printf("\n Inserisci 1 per spostarti a sud.\n Inserisci 2 per spostarti ad est. \n Inserisci 3 per spostarti a nord. \n Inserisci 4 per spostarti ad ovest.\n");
        scanf("%d", &sposta);
       
            if(sposta<1 || sposta>4){
             printf("\n ERRORE!! Inserisci un numero compreso tra 1 e 4 inclusi\n");
            }
            pulizia;

        }while (sposta<1 || sposta>4);

                switch (sposta){
                case 1: if(Player->y+1>num_celle-1) printf("Sei al bordo della mappa, non puoi muoverti in questa direzione!");
                 else{
                     Player->y=Player->y+1;}
                break;
                case 2: if(Player->x+1>num_celle-1) printf("Sei al bordo della mappa, non puoi muoverti in questa direzione!");
                else{
                     Player->x=Player->x+1;}
                break;
                case 3: if(Player->y-1<0) printf("Sei al bordo della mappa, non puoi muoverti in questa direzione!");
                else{ 
                    Player->y=Player->y-1;}
                break;
                case 4: if(Player->x-1<0) printf("Sei al bordo della mappa, non puoi muoverti in questa direzione!");
                else{
                    Player->x=Player->x-1;}            
                } 
                if(scacchiera[Player->x*num_celle+Player->y].pericolo==nessun_pericolo) printf("\n Non hai trovato alcun pericolo!");
                if(scacchiera[Player->x*num_celle+Player->y].pericolo==alieno){
                    funcalieno();                                   
                }
                if(scacchiera[Player->x*num_celle+Player->y].pericolo==trappola){
                    functrappola();                        
                }
                if(Player->stato==morto) return;

                if (scacchiera[Player->x*num_celle+Player->y].oggetto!=nessun_oggetto){
                    if(scacchiera[Player->x*num_celle+Player->y].oggetto==medikit){
                        printf("\n Hai trovato un medikit!\n");
                        appoggio_1=medikit;
                    }
                    if(scacchiera[Player->x*num_celle+Player->y].oggetto==pozione){
                        printf("\n Hai trovato una pozione!\n");
                        appoggio_1=pozione;
                    }
                    if(scacchiera[Player->x*num_celle+Player->y].oggetto==materiale){
                        printf("\n Hai trovato del materiale!\n");
                        appoggio_1=materiale;
                    }
                    if(scacchiera[Player->x*num_celle+Player->y].oggetto==colpi_lanciarazzi){
                        printf("\n Hai trovato un colpo per il lanciarazzi!\n");
                        appoggio_1=colpi_lanciarazzi;
                    }                    
                }
                else{
                    printf("\n Non hai trovato alcun oggetto!\n");
                }
                 _Bool controllo=0;
                 int spazio=0;

                for(int z=0; z<4; z++){
                   if(Player->zaino[z]==nessun_oggetto){
                       controllo=1;
                       spazio=z;
                       }
                }

                if(controllo){
                    Player->zaino[spazio]=appoggio_1;
                    scacchiera[Player->x*num_celle+Player->y].oggetto=nessun_oggetto;
                }
                else{
                    
                    printf("\n Oh no!Mi dispiace ma lo zaino è pieno!\n");
                    stampazaino();
                    int cambio;
                    do{
                    printf("\n Se vuoi puoi decidere quale oggetto sostituire!\n 1 per sostiuire il primo;\n 2 per il secondo;\n 3 per il terzo;\n 4 per il quarto; \n 5 per lasciare gli oggetti che già possiedi!\n");
                    scanf("%d",&cambio);}while(cambio<1 && cambio>5);
                    switch(cambio){
                        case 1: Player->zaino[0]=appoggio_1;
                        scacchiera[Player->x*num_celle+Player->y].oggetto=nessun_oggetto;
                        break;
                        case 2: Player->zaino[1]=appoggio_1;
                        scacchiera[Player->x*num_celle+Player->y].oggetto=nessun_oggetto;
                        break;
                        case 3: Player->zaino[2]=appoggio_1;
                        scacchiera[Player->x*num_celle+Player->y].oggetto=nessun_oggetto;
                        break;
                        case 4: Player->zaino[3]=appoggio_1;
                        scacchiera[Player->x*num_celle+Player->y].oggetto=nessun_oggetto;
                        break;
                        case 5:
                        break;
                    }
                    if(cambio<5) stampazaino();

                }
    int stop;
    do{
        printf("\n\nClicca 1 per andare avanti!! ");
        scanf("%d",&stop);
    }while(stop!=1);

            scacchiera[Player->x*num_celle+Player->y].pericolo=nessun_pericolo; // vengnono eliminati i pericoli dove sono già passati i giocatori
            Player->turno_G++;
            turno++;

            
            
}

void usa_oggetto (){
    int usa_ogg;
    do{
        printf("\n Quale oggetto vuoi usare?\n 1 per il medikit; \n 2 per la pozione; \n 3 per i materiali; \n 4 per i colpi del lanciarazzi; \n 5 per tornare indietro");
        scanf("%d",&usa_ogg);
    }while(usa_ogg<1 && usa_ogg>5);
    _Bool controllo=0;
      
    switch(usa_ogg){
        case 1: for(int z=0; z<4; z++){
                    if(Player->zaino[z]==medikit){
                    controllo=1;
                    Player->zaino[z]=nessun_oggetto;
                    break;
                    }                    
                }
        if (controllo){
            if (Player->stato==solo_vita || Player->stato==scudo_vita) printf("\n Non hai alcun bisogno di usare il medikit!");
            if (Player->stato==solo_scudo) Player->stato=scudo_vita;
            if (Player->stato==vulnerabile) Player->stato=solo_vita;
        }
        else{
            printf ("\n Nello zaino non sono presenti medikit!\n");
        }
        break;
        case 2: for(int z=0; z<4; z++){
            if(Player->zaino[z]==pozione){
                controllo=1;
                Player->zaino[z]=nessun_oggetto;
                break;
            }
        }
        if(controllo){
            if (Player->stato==solo_scudo || Player->stato==scudo_vita) printf("\n Non hai alcun bisogno di usare la pozione!");
            if (Player->stato==vulnerabile) Player->stato=solo_scudo;
            if (Player->stato==solo_vita) Player->stato=scudo_vita;
            
        }
        else{
            printf("\n Nello zaino non sono presenti pozioni!\n");
        }
        break;
        case 3:
        case 4: printf("\n Puoi usare i materiali e i colpi del lanciarazzi solamente nel duello finale!\n");
        break;
        case 5:
        break;

    }

}

void funcalieno(){
    int scelta;
    int k;
    k=prob;
    printf("\n Hai trovato un alieno!!\n Se decidi di combattere prendi l'eventuale oggetto che si trova nella casella attuale\n ma rischi di perdere la vita o lo scudo!\n ");
    do{
    printf("\n Clicca 1 per combattere! 2 per evitare l'alieno!");
    scanf("%d", &scelta);
    if (scelta!=1 && scelta!=2){
        pulizia; 
        printf("\n ERRORE!! \n Inserisci 1 o 2!");
    }
    }while(scelta!=1 && scelta!=2 );
    
    switch(scelta){
        case 1: printf("\n Hai sconfitto l'alieno!!");
                if(k<=35) printf("\n Che fortuna, non hai perso nè la vita nè lo scudo!\n");
                else{
                    if (k<=65){
                        if (Player->stato==vulnerabile){ 
                            Player->stato=morto; 
                            printf("\n Non hai lo scudo e nemmeno la vita!!");
                            stampastato();
                        }
                        if (Player->stato==solo_vita){ 
                            Player->stato=vulnerabile; 
                            printf("\n Hai perso la vita!!");
                            stampastato();
                        }
                        if (Player->stato==scudo_vita){ 
                            Player->stato=solo_vita;
                            printf("\n Hai perso lo scudo!\n");
                            stampastato();
                        }
                        if (Player->stato==solo_scudo){
                            Player->stato=vulnerabile; 
                            printf("\n Hai perso lo scudo!\n");
                            stampastato();
                        }
                    }
                    else{
                        
                           if(Player->stato==vulnerabile){
                           Player->stato=morto; 
                           printf("\n Non hai lo scudo e nemmeno la vita!!");
                           stampastato();
                        }
                        if(Player->stato==solo_vita){
                            Player->stato=vulnerabile; 
                            printf("\n Hai perso la vita!!");
                            stampastato();
                        }
                        if(Player->stato==solo_scudo){
                            Player->stato=vulnerabile; 
                            printf("\n Hai perso lo scudo!\n");
                            stampastato();
                        }
                        if(Player->stato==scudo_vita){
                            Player->stato=solo_scudo;
                            printf("\n Hai perso la vita"); 
                            stampastato();
                        }
                        
                    }

                }
                Player->alieni_uccisi++;
                break;

        case 2: printf("\n Hai evitato l'alieno, ma l'oggetto e\' stato eliminato");
                scacchiera[Player->x*num_celle+Player->y].oggetto=nessun_oggetto;
                break;
    }


}

void functrappola(){
    int soldo;
    int k;
    k=prob;
    printf("\n Hai trovato una trappola, hai solo una possibilità di sopravvivere, quella di giocare a testa o croce!\n ");
    do{
        printf("\n Inserisci 1 per scegliere testa o 2 per scegliere croce!\n");
        scanf("%d", &soldo);
        if (soldo!=1 && soldo!=2){
            pulizia; 
            printf("\n ERRORE!! Inserisci 1 o 2");
        }
    }while(soldo!=1 && soldo!=2);

            switch(soldo){
                case 1:
                    printf("\n Hai scelto testa!\n");
                    if (k<50){
                        printf("\n Hai vintoooo! Sei rimasto in vita");
                    }
                    else{
                        printf("\n Sei mortoo!"); 
                        Player->stato=morto;
                    }
                    break;
                case 2:
                    printf("\n Hai scelto croce!\n");
                    if (k<50){
                        printf("\n Hai vintoooo! Sei rimasto in vita");
                    }
                    else{printf("\n Sei mortoo!");
                    Player->stato=morto;
                    }
                    break;
                }                
    }
    


void stampastato(){
    switch(Player->stato){
        case 0: printf("\n Lo stato del giocatore e\': vulnerabile!");
                break;
        case 1: printf("\n Lo stato del giocatore e\': vita e scudo");
                break;
        case 2: printf("\n Lo stato del giocatore e\': solo vita");
                break;
        case 3: printf("\n Lo stato del giocatore e\': solo scudo");
                break;
        case 4: printf("\n Il giocatore è morto!!!!");
                break;
    }
}

void stampazaino(){
    printf("\n Zaino:\n");
    for (int z=0; z<4; z++){
        switch(Player->zaino[z]){
            case 0: printf("[%d]--> nessun oggetto\n", z+1);
            break;
            case 1: printf("[%d]--> medikit\n", z+1);
            break;
            case 2: printf("[%d]--> pozione\n", z+1);
            break;
            case 3: printf("[%d] --> materiali\n", z+1);
            break;
            case 4: printf("[%d]--> colpi lanciarazzi\n", z+1);
            break;
        }
    }
    
}

void termina_gioco(){
    if(Ciccio.stato==morto){
        printf("\n Ciccio e\' MORTOO!\n IL VINCITORE E\' NINJA");
    }
    if(Ninja.stato==morto){
        printf("\n Ninja e\' MORTOO!\n IL VINCITORE E\' CICCIO");
    }
    printf("\n La partita è finita!!");
    printf("\n Ciccio ha fatto %d uccisioni", Ciccio.alieni_uccisi);
    printf("\n Ninja ha fatto %d uccisioni", Ninja.alieni_uccisi);
    exit(EXIT_SUCCESS);
}

void nuova_partita(){

    Ciccio.stato= solo_vita;
    Ninja.stato= solo_vita;
    Ciccio.alieni_uccisi=0;
    Ninja.alieni_uccisi=0;
    for(int z=0; z<4; z++){
        Ciccio.zaino[z]=nessun_oggetto;
    }
    for(int z=0; z<4; z++){
        Ninja.zaino[z]=nessun_oggetto;
    }
    int stop;
    do{
        printf("\n\nClicca 1 per andare avanti!! ");
        scanf("%d",&stop);
    }while(stop!=1);
    menu();
}

void restri_mappa(){
        pulizia;
     for (int i=0; i<num_celle; i++){
            for (int j=0; j<num_celle; j++){                              //stampo nuovamente la mappa..          
                                                                        //.. prima di fare il restringimento
                if(Ciccio.y==i && Ciccio.x==j) printf ("Ciccio");
                else{
                    if (Ninja.y==i && Ninja.x==j) printf (" Ninja");
                 else{
                 printf(" [%d %d]", i, j);
                 }
                }
            }
            printf("\n");
        }
    printf("\n\n");
    printf("\n RESTRINGIMENTO MAPPA \n");
    free(scacchiera);
    num_celle=num_celle/2;
    scacchiera=malloc(num_celle*num_celle*sizeof(struct Cella));
    _Bool presenzaC=0, presenzaN=0;
    int k=prob;
    for(int i=0; i<num_celle; i++){
        for(int j=0; j<num_celle; j++){
            if(k<=nex_per)  scacchiera[i*num_celle+j].pericolo= nessun_pericolo; //lascio le vecchie percentuali
            else {                                                                          //inserite dall'utente
                if(k<=nex_per+ali) scacchiera[i*num_celle+j].pericolo= alieno;   // degli oggetti e dei pericoli
                else{
                    if(k<=nex_per+ali+trap) scacchiera[i*num_celle+j].pericolo= trappola;
                }         
            }               
            if(k<=nex_ogg) scacchiera[i*num_celle+j].oggetto= nessun_oggetto;
            else{
                if(k<=nex_ogg+mdk) scacchiera[i*num_celle+j].oggetto= medikit;
                else{
                    if(k<=nex_ogg+mdk+poz) scacchiera[i*num_celle+j].oggetto= pozione;
                    else{
                        if(k<=nex_ogg+mdk+poz+mat) scacchiera[i*num_celle+j].oggetto= materiale;
                        else{
                            if(k<=nex_ogg+mdk+poz+mat+razzi) scacchiera[i*num_celle+j].oggetto= colpi_lanciarazzi;
                        }
                    }
                }
            }
            if(Ciccio.y==i && Ciccio.x==j){
                 Ciccio.y=i;
                 Ciccio.x=j;
                presenzaC=1;
             }
             if(Ninja.y==i && Ninja.x==j){
                Ninja.y=i;
                Ninja.x=j;
                 presenzaN=1;
             }
        }
    }

    if(!presenzaC) Ciccio.stato=morto;
    if(!presenzaN) Ninja.stato=morto;

    for (int i=0; i<num_celle; i++){
            for (int j=0; j<num_celle; j++){                              //stampo nuovamente la mappa..          
                                                                        //.. prima di fare il restringimento
                if(Ciccio.y==i && Ciccio.x==j) printf ("Ciccio");
                else{
                    if (Ninja.y==i && Ninja.x==j) printf (" Ninja");
                 else{
                 printf(" [%d %d]", i, j);
                 }
                }
            }
            printf("\n");
        }


}

void round_finale(){
    pulizia;
    static struct Giocatore *Nemico;
    int scelta;
    
    
printf("\n Ciccio e Ninja si sono ritrovati sulla stessa casella!!\n Che lo scontro finale abbia inizio!!\n Che vinca il migliore!\n");
printf("\n Nella battaglia finale puoi usare i materiali per costruire il tuo fortino pronto a difenderti;\n puoi usare il fucile di precisione per cercare di colpirlo;\n puoi usare il lanciarazzi per distruggere il suo fortino o per cercare di colpirlo; \n e puoi infine usare gli oggetti presenti nello zaino!");


do{
 _Bool booleano=0;
 _Bool colpi=0;
 int num;
if(turno%2==0){
    Player=&Ciccio;
    Nemico=&Ninja;
    printf("\n E\' il turno di Ciccio!\n");
}
else{
    Player=&Ninja;
    Nemico=&Ciccio;
    printf("\n E\' il turno di Ninja!\n");
}

printf("\n[1]->Costruisci fortino.\n[2]->Fucile di precisione.\n[3]->Lanciarazzi.\n[4]->Usa oggetto.\n");
scanf("%d", &scelta);
pulizia;

switch(scelta){
    case 1: for(int z=0; z<4; z++){
                if(Player->zaino[z]==materiale){
                    booleano=1;
                    Player->zaino[z]=nessun_oggetto;
                    break;
                }
            }
            if(booleano) aggiungi_piano();
            else printf("\n Non hai materiali per costruire il fortino!");
            break;
    case 2: if (Nemico->Ultimo_piano!=NULL) num=Nemico->Ultimo_piano->n_piano*10;
            else num=0;
            if (prob<=10 + Player->alieni_uccisi*10 - num){
            printf("\n Hai ucciso il tuo nemico!!!");
            Nemico->stato=morto;
            }
            else printf("Hai mancato il bersaglio!");
            getchar();
            break;
    case 3: for(int z=0; z<4; z++){
                if(Player->zaino[z]==colpi_lanciarazzi){
                    colpi=1;
                    Player->zaino[z]=nessun_oggetto;
                    break;
                }
             }
             if(colpi) elimina_piano(Nemico);
             else printf("\n Non hai nessun colpo per il lanciarazzi!");
             getchar();
             break;
    case 4: stampazaino();
            usa_oggetto();
            break;
}
turno++;
}while(Ciccio.stato!=morto && Ninja.stato!=morto);

}

void aggiungi_piano(){
   P_N *nuovo_piano= malloc(sizeof(P_N));
   P_N *fantasia=NULL;
   nuovo_piano->ProssimoPiano=NULL;
    

   if(Player->Torre==NULL){
      printf("\n Hai costruito una parete del tuo fortino!\n");
      Player->Torre=nuovo_piano;
      Player->Ultimo_piano=nuovo_piano;
      nuovo_piano->n_piano=1;
   }
   else{
        printf("\n Hai costruito un'altro pezzo del tuo fortino!\n");
        Player->Ultimo_piano->ProssimoPiano=nuovo_piano;
        Player->Ultimo_piano=nuovo_piano;
   }
}

void elimina_piano(struct Giocatore* Nemico){
    P_N *fantasia=NULL;
    if(Nemico->Torre==NULL)
        printf("Non ci sono piani da distruggere!\n");
    else{
        fantasia = Nemico->Torre;
        while(fantasia->ProssimoPiano!=Nemico->Ultimo_piano){
            fantasia=fantasia->ProssimoPiano;
        }
        free(Nemico->Ultimo_piano);
        fantasia->ProssimoPiano=NULL;
        Nemico->Ultimo_piano=fantasia;
        printf("TORRE ABBATTUTA!\n");
    }
}

void stampa_diagonale(){
     if (scacchiera==NULL) {
        printf("\n ERRORE!! \n NON HAI ANCORA CREATO LA MAPPA");
        crea_scacchiera();
        }
        pulizia;
    int conta_trap=0, conta_alien=0;
    
    for(int i=0; i<num_celle; i++){
       for(int j=0; j<num_celle; j++){
        if(i==j){
            if(scacchiera[i*num_celle+j].pericolo==trappola) conta_trap++;
            if(scacchiera[i*num_celle+j].pericolo==alieno) conta_alien++;
        }
       }
    }
    printf("\n Il numero di trappole nella prima diagonale e\'--> %d", conta_trap);
    printf("\n Il numero di alieni nella prima diagonale e\' -->%d", conta_alien);
    int verifica;
    do{
        printf("\n\n\n Clicca 1 per andare avanti");
        scanf("%d", &verifica);
    } while(verifica!=1);
    crea_mappa();

}