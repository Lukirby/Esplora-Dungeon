//created by Giulia Torsani 

#include "Elements2.hpp"

class Player : public Entity{
    protected: 

    //Contatore Chiavi - K
    int KeyCounter;
    
    //Presenza di Scudo - S
    bool Shield;

    //Presenza di Mantello - C
    bool Coat;

    //N_Proiettili Disponibili - B
    int Bullets;

    //Il Player è dentro i muri speciali?
    bool InGlass;

    public:
    
    //Costruttore
    Player(WINDOW* curwin=NULL,Coordinates coords = Coordinates(0,0), char c='@',int pv=1, int damage=1, int score=0, int lvl=1, bool isdead=false, 
    int KeyCounter=0, bool Shield=false, bool Coat=false, int Bullets=0, bool Weapon= false);


    //prende l'artefatto
    void getartefact(Artefact A); 
    
    //Ritorna Stato Scudo - S
    bool hasShield();
    
    //Toggle Scudo - S
    //inverte il valore del booleano
    void editShield();
    
    //Toggle Mantello - C
    //inverte il valore del booleano
    void editCoat();

    //controlla se è invisibile
    bool hasCoat();                
    
    //ritorna se abbiamo chiavi
    int getKeys();              

    //incrementa o meno il numero di chiavi
    void editKeys(int key);     

    //Ritorna il numero di Proiettili
    int getBullets();

    //Modifica il Numero di Proiettili
    void editBullets(int bul);
    
    //controllo se è dentro ai muri che si varcano solo col mantello
    bool isinglass();           
    
    //modifico il booleano InGlass
    void editInGlass();
    
    /*
    dal l1 al l3 si aumenta di 150pt (si arriva a 450)
    dal l3 al l8 si aumenta di 200pt (si arriva a 1450)
    dal l8 a l13 si aumenta di 250pt (si arriva a 2700)
    dal 13 in poi si aumenta di 300pt
    */
    void levelmanager();
    
};