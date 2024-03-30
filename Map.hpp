//created by Luca Panariello 
#include "TreeRoom.hpp"
using namespace std;


class Map{
    protected:
    TreeRoom TR;                //Struttura che Raccoglie le Stanze
    Coordinates start;          //Dove stampare le stanze nello schermo
    Coordinates length;         //La Dimensione delle Stanze                     
    WINDOW* screen;             //Schermo delle Stanze

    //Cancella i caratteri presenti sullo schermo
    void clean_screen();        
    //Crea una Stanza
    void generate_room(int i,int lvl);  
    //Cambia Stanza
    void change_room(int x);    

    public:
    //Costruttore Predefinito - Inutilizzato
    Map();                      
    //Costruttore
    Map(int sy,int sx);

    //Esplora le Stanze e Crea o Cambia Stanza a seconda della Necessità
    bool explore(int i, int lvl);        

    //Ritorna lo Schermo
    WINDOW* get_screen();

    //Ritorna la Stanza Corrente - Mediante Costruttore Copia
    Room getRoom();             

    //Ritorna Artefacthandler della stanza Corrente - Mediante Costruttore Copia
    ArtefactHandler getArtefactHandler(); 

    //Ritorna Artefacthandler della stanza Corrente - Mediante Costruttore Copia
    EnemiesHandler getEnemiesHandler();

    //Aggirna lo Schermo , Ristampando Stanze, Artefatti e Nemici
    void reload();              
    
    //Rimuove le Porte
    void unlock();    

    //Rimuove Artefatto
    Artefact RemoveArtefact(char A, Coordinates C);  
    
    //Rimuove Nemico nel caso i suoi pv raggiungano 0
    int RemoveEnemy(int damage,Coordinates C);

    //Fase del Nemico -> Manda un imput a EnemiesHandler per far agire i nemici, muovendoli o facendogli sparare
    int EnemyPhase(Coordinates PlayerC);

    //Ritorna la direzione opposta;
    int opposite(int n);        
};