//created by Luca Panariello 
#include "EnemiesHandler.hpp"

//Struttura dati ad albero 4-ario in cui ogni nodo è presente
//Una stanza e i relativi artefatti e nemici
struct Tree{
    Room R;             //Stanza
    ArtefactHandler AH; //Struttura Dati Artefatti
    EnemiesHandler EH;  //Struttura Dati Nemici
    //Direzioni dell'Albero Basata su Array di Puntatori
    //su=0, dx=1, giù=2, sx=3
    Tree* D[4];         
};

class TreeRoom {
    protected:
    //Struttura ad Albero
    Tree* T;             
    //Genera un Nodo Albero
    Tree* generate_tree(Room room, int entrance, Tree* N, ArtefactHandler AH, EnemiesHandler EH); 
    public:
    //Costruttore Predefinito - Inutilizzato
    TreeRoom();
    //Costruttore                             
    TreeRoom(Room room,ArtefactHandler HA,EnemiesHandler EH); 

    //Ritorna la direzione opposta
    int opposite(int i);                    

    //Inserisce una stanza nella Struttura
    void insert (Room room, int direction, ArtefactHandler HA, EnemiesHandler EH); 
    
    //Navigare nella Struttura
    void move (int direction);              
    
    //Ritorna la Stanza Corrente - Mediante Costruttore Copia
    Room current_room();                    
    
    //Ritona il Nodo di una certa Direzione
    Tree* get_tree_direction(int d);             
    
    //Ritorna il Gestore di Artefatti - Mediante Costruttore Copia
    ArtefactHandler getAH();                
    
    //Ritorna il Gestore di Nemici - Mediante Costruttore Copia
    EnemiesHandler getEH();

    //Rimuove Artefatto
    Artefact RemoveArtefact(char A, Coordinates C); 

    //Rimuove Nemico
    int RemoveEnemy(int damage,Coordinates C);
    
    //La struttra EnemiesHander Prepara i Nemici ad attaccare o muoversi
    int EnemyPhase(Coordinates PlayerC);

    //Rimuove le Porte
    void unlock();     

    void showEnemies();                     
};