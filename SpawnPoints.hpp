//created by Luca Panariello 
#include "LoC.hpp"

class SpawnPoints{
    protected:
    //Block_Enemies  - 0
    //Free_Enemies   - 1
    //Free_Artefact  - 2
    //Glass_Artefact - 3
    //Array di Liste che raccoglie i SpawnPoint di Artefatti e Nemici
    LoC SP[4];                           

    int stx, sty;                   //Dimensione della Stanza

    public:
    //Costruttore
    SpawnPoints();                  

    //Inizializza gli SpawnPoint in base alla Stanza
    void build(Room R,bool fr);     

    //Estrae casualmente una Coordinata da una delle Liste
    Coordinates extract(int sp);    
    
    //Ritorna il numero di Coordinate relative agli Artefatti presenti
    int get_nArtefact();            
    
    //Ritorna il numero di Coordinate relativa ai Nemici presenti
    int get_nEnemies();                 
};