//created by Luca Panariello 
#include "Walls.hpp"
using namespace std;

class Room {
    protected:
    //schermo della stanza
    WINDOW *room_win;     

    //coordinate che indicano la dimensione della stanza la stanza
    Coordinates length;         

    //da dove entra il giocatore
    int entrance;               

    //numero di uscite (non contanto l'entrata)
    int n_exit;                 

    //indica se la stanza ha porte
    bool has_door;              

    //booleano che indica se è la prima stanza creata
    bool first_room;            

    //Uscite della Stanza
    Exits exit;          

    //Porte della Stanza
    Doors door;                 
    
    //Muri della Stanza
    Walls wall;                 
    
    public:
    //Costruttore
    Room(int ly=0, int lx=0, int entrance=0, WINDOW* play=NULL, bool from_door=false, bool first_room=true);
    
    //Ritorna i Muri - Viene Ritornato una Classe Creata con Costruttore Copia
    Walls getWalls();           
    
    //Stampa la Stanza
    void print_room();          

    //Ritorna le Uscite
    Exits get_Exit();           

    //Ritorna le Porte
    Doors get_Doors();

    //Sblocca La Porta della Stanza Mediante Chiave - K
    void unlock();

    //Ritorna lo schermo della stanza
    WINDOW* getScreen();        
};