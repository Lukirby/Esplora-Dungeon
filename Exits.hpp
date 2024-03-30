//created by Luca Panariello
#include "Player.hpp"


class Exits {
protected:
    //Cordinate della Stanza
    Coordinates start;
    
    //Carattere che verrà stampato in corrispondeza delle uscite  
    char c;             
    
    //Array di Uscite : 0 - nord, 1 - est, 2 - sud, 3 - ovest
    //Booleani che indicano se c'è un uscita oppure no
    bool E[4];          
    
    //Finestre in cui verranno stampate le uscite
    WINDOW* room;       

public:
    // Costruttore Predefinito - Inutilizzato
    Exits();

    // Costruttore
    Exits(char c,int startx, int starty, WINDOW* room);
    
    //Inizializza le Uscite casualmente - Utilizzando l'entrata in input
    //Inizializzazione diversa per quanto riguarda la prima stanza del gioco
    void build(int entrance, int n_exit, bool first);   
    
    //Stampa le Uscite
    void print();                                       

    //Ritorna l'Array di Uscite
    void getArray(bool S[]);                            
};