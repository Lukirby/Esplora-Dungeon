//created by Giulia Torsani
#include "Shooter.hpp"

using namespace std;


class Entity{

    protected:

   Coordinates coordinates;
    char character;
    int pv;//punti vita
    int damage;//punti danno
    int score;//punteggio
    int lvl;//livello corrente
    bool isdead;//entità muore quando pv<=0 (pv massimi = 100)
    int maxLife;//vita massima che si incrementa di 10 ogni volta che si raccoglie l'artefatto 'A'
    Shooter S;
    WINDOW* curwin;
    
    
    public:

    Entity(WINDOW* curwin=NULL,Coordinates coords = Coordinates(0,0), char c='E',int pv=1, int damage=1, int score=0, int lvl=1, bool isdead=false);

    void setCoordinates(Coordinates coords = Coordinates(0,0));

    Coordinates getCoordinates();

    void setpv(int pv);
    
    int getpv();

    int getMaxLife();

    void editpv(int points);// se pv tolti si somma un numero negativo

    void setdamage(int damage);

    int getdamage();

    void setscore(int score);
    
    int getscore();

    void setLevel(int lvl);

    int getLevel();

    void setchar(char c);
    
    char getchar();

    bool getisdead();

    void checkisdead();

    void mvup();

    void mvdown();

    void mvleft();

    void mvright();

    void getmv(int choice);

    void display();

    Shooter useShoot();

    void setShoot();
};