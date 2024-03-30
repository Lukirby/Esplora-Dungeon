//created by Luca Panariello 
#include"Gamestate.hpp"

//è sottoclasse di Interaction, utilizza tramite Ereditarietà le funzioni Check di Interaction
class MapHandler:public Interaction{
    protected:
    //Mappa di Gioco
    Map M;                  
    Player P;               //Giocatore
    int direction;          //direzione presa
    int action;             //azione eseguita
    Gamestate G;            //Informazioni sul Giocatore -- Stato di Gioco
    
    //registra l'azione da eseguire
    void get_action(int c); 

    //registra la direzione voluta
    void get_direction();       

    //prevede la posizione futura possibile e controlla se può essere effettuata
    void next_position();       

    //Controlla se è possibile cambiare stanza
    bool CheckScene();          

    //Cambia Stanza
    void ChangeScene();         
    
    //Raccoglie Artefatto
    void PickArtefact();        

    //Sblocca le Porte in caso si sia in possaso di una Chiave K
    void UnlockDoors();         

    //"teletrasporta" il giocatore in un' altra stanza
    void warpPlayer();          

    //oltrepassa i muri speciali
    bool miniWarp();            

    //supera i muri speciali se si è nelle condizioni
    void BeyondWalls();         

    //Il Player si Sposta 
    void PlayerMovement();

    //Il Player Esegue un'azione
    void PlayerAction();            

    //Il Player sparra in una direzione
    void PlayerShot();

    //Il player Sferra un Attacco Ravvicinato
    bool PlayerRawAttack();

    //Il Nemico Viene Colpito e nel caso i suoi pv raggiungano 0 esso viene eliminato
    void KillEnemy(Coordinates C,int damage);

    //Fase Nemico scegli se muoversi , attaccare o stare fermo
    void EnemyPhase();

    //Aggiorna lo Schermo
    void Display();

    public:
    //Costruttore Predefinito - Inutilizzato
    MapHandler();           

    //Costruttore
    MapHandler(int xMax, int yMax, Coordinates max=Coordinates(0,0), Coordinates cursor=Coordinates(0,0), char c='0', WINDOW* curwin=NULL);

    //Controlla e Riporta se il Giocatore è Morto oppure no
    bool PlayerDeath();

    //Ciclo di Gioco
    void PlayGame();            

    //Arresta il Gioco
    void CloseGame();           
};
