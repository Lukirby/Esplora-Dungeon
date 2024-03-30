//created by Federica Santisi

/* La classe Enemies2 è la classe identità del nemico dove vengono implementati i vari 
metodi che ritornano le carattistiche principali che abbiamo associato ai nemici quali la
possibilità di sparare, il movimento e l'arma per l'attacco ravvicinato.
*/
#include "Movement2.hpp"

class Enemy : public Entity{
private:
    int move;
    int shoot;
    bool just_shoot;
    bool armed;
    Movements M;
    CheckPlayer CP;

public:
    Enemy(WINDOW* curwin=NULL,Coordinates coords = Coordinates(0,0), char c = '@', int pv = 10,
    int damage = 1, int score = 10, int lvl = 0, bool isdead = false, 
    int move = 0, int shoot = 0, bool just_shoot = false, bool armed = false);//:Entity(coords,c,pv,damage,score,lvl,isdead){};

    int Is_move();
    
    int Is_shooting();

    bool Is_armed();

    void Moving(Coordinates PlayerC);

    int Shooting(Coordinates PlayerC);

    int Armed(Coordinates PlayerC);
};