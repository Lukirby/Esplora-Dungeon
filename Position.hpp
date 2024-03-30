//created by Federica Santisi
/*La classe Position controlla il tipo di carattere presente nella posizione attuale*/
#include "CheckPlayer.hpp"

class Position{
protected:
    char current_position;
    WINDOW *curwin;
    Coordinates c;
public:
    Position(WINDOW *curwin = NULL);

    bool Check_lenght(Coordinates c);
    bool Check_Player(Coordinates c);
    bool Check_enemies(Coordinates c);
};