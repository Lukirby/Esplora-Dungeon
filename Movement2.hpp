//created by Federica Santisi 
#include "Entity.hpp"
//Versione Finale

/* La classe movements implementa i tipi di movimento del nemico all'interno del gioco
1)entità ferma (non si ha incremento delle coordinate)
2a)avanti e indietro da un punto (y+4, y-4)
2b)avanti e indietro da un punto (x+4,x-4)
3)inseguimento del personaggi
4a)si muove in orizzontale da muro a muro
4b)si muove verticalmente da muro a muro
*/

class Movements : public Coordinates{
protected: 
    int cont;
    bool check;
    int xp; int xe;
    int yp; int ye;
    Interaction I;
public:
    Movements(WINDOW* curwin=NULL,int x = 0, int y = 0);

//metodi che definisco il tipo di movimento 2a e 2b
    Coordinates move_y(Coordinates C);
    Coordinates move_x(Coordinates C);
//si muove in orizzontale o verticale da muro a muro
    Coordinates Hit_walls_x(Coordinates C);
    Coordinates Hit_walls_y(Coordinates C);

//insegue il personaggio scegliendo sempre la coordinata che lo fa avvicina di più al player
    Coordinates Chase_Player(Coordinates EnityC, Coordinates PlayerC);
};