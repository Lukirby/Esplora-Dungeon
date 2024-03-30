//created by Luca Panariello
#include "Exits.hpp"

//Le Porte sono indicate con X
class Doors: public Exits{
protected:
    //Booleano che indica se vi è una porta
    bool has_door; 
    int where_is_door; //intero che indica dove si trova la porta (-1 in caso non ci sia)
public:
    //Costruttore di Default - Inutilizzato
    Doors();                                                    

    //Costruttore
    //SottoClasse di Exit, permette di usare le funzioni di inizializzazione,
    //stampa e ritorno, sfuttando l'ereditarietà
    Doors(char c,int startx, int starty, WINDOW* room);         
    
    //Sovrascrittura: Inzializzo le Porte Casualmente
    void build(int n_exit, int entrance, bool E[], bool first); 
    
    //Ritorna se c'è una Porta
    bool getHasDoor();

    //Ritorna in quale uscita si trova la porta
    int getWhereIsDoor();
};