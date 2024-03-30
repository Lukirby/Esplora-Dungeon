//created by Luca Panariello
#include "Doors.hpp"

class Walls {
    protected:
    //Coordinate dei Muri Sud e Est
    int stx, sty;

    //Array di Interti che indica che tipo di muro c'è nella stanza
    //ai lati(0,1,2,3), in mezzo (4,5) , agli angoli (6,7,8,9), al centro (10)
    int W [11];

    //Booleano che indica se vi sono muri speciali
    bool has_glass; 

    //Finesta in cui verranno stampati i muri
    WINDOW* play;

    //stampa una linea di caratteri - Generalizzazione 
    void print_lines(int start, int end, int position, char c, bool direction);       

    //stampa un quadrato di caratteri - Generalizzazione
    void print_square(int ul, int ur, int dl, int dr, bool special, bool direction);
    
    //stampa il quadrato al centrto della stanza - Generalizzazione
    void print_central_square(int ul,int ur, int dl, int dr, bool holed, char c);       
    
    public:
    //Costruttore Predefinito - Inutilizzato
    Walls();                                                        

    //Costruttore
    Walls(bool E[], int sty, int stx, WINDOW* play, bool first);    

    //Ottieni Tipo di Muro
    int getWall(int i);                                             

    //Stampa i Muri
    void print();

    //Ritorna un Booleno che Indica se vi è un Muro Speciale
    bool get_GlassInfo();                                           
};