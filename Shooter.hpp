//created by Federica Santisi 
//La classe shooter implementa la funzionalità di sparare dei nemici e del personaggio
//nel caso in cui prendesse l'artefatto "Proiettile" -> B
//una volta raccolto ,Il Giocatore ha diritto a 10 colpi
//e ogni colpo leva al nemico una tacca di vita

#include "Position.hpp"

class Shooter{
private:
    char bv;
    char bh;
    int wait;
    int wait2;
    bool found;
    int TypeShoot[3];
    WINDOW *curwin;
    Coordinates c;
    Position p;

public:
    Shooter();
    Shooter(WINDOW *curwin, Coordinates c);
    
    Coordinates Shoot_up();
    Coordinates Shoot_down();
    Coordinates Shoot_left();
    Coordinates Shoot_right();

    void Print_bullet();

    bool Check_entity(Coordinates c); 

    void Set_Coordinates(Coordinates c);   

};