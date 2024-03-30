//created by Luca Panariello
#include "Coordinates.hpp"

class Interaction{
    protected:

    //Coordinate che Segnano i Bordi sud e est
    Coordinates max;
    
    //Coordinate del Cursore
    Coordinates cursor;
    
    //Carattere Preso dallo Schermo
    char c;
    
    //Coordinate di tutti i bordi 
    //0 = nord, 1=est, 2=sub e 3=ovest
    int Border[4];
    
    //Finestra in cui vengono effettuati i controlli
    WINDOW* curwin;
    
    //legge il carattere sullo schermo
    char readChar();

    //Medoto Ausiliario che controlla se tra il giocatore e il nemico non ci sono ostacoli
    int checkInSight(int d);

    public:
    //Costruttore
    Interaction (Coordinates max=Coordinates(0,0), Coordinates cursor=Coordinates(0,0), char c='0', WINDOW* curwin=NULL);

    //Ritorno se c'è un muro oppure no
    bool checkWalls();

    //Ritorno se c'è un'uscita oppure no
    bool checkExits();

    //Ritorno se c'è un bordo oppure no
    bool checkBorder(int i);

    //Ritorno se c'è un artefatto oppure no
    bool checkArtefact();

    //Ritorno se c'è una porta oppure no
    bool checkDoors();

    //Ritorno se c'è un muro speciale oppure no
    bool checkSpecialWalls();

    //Controlla che vi sia un Nemico
    bool checkEnemy();

    //Controlla che il player sia in linea d'aria con il nemico, nel caso ritorna la direzione in cui sparare
    int CheckPlayerSight(Coordinates PlayerC);

    //Controlla che il player sia vicino al nemico
    bool checkPlayerNextEnemy(Coordinates PlayerC);

    //Imposto il cursore di controllo manualmente
    void setCursor(Coordinates c);
};