//created by Federica Santisi 

#include "Position.hpp"

Position::Position(WINDOW *curwin){
    this -> curwin = curwin;
};

//Ritorna true se spazio vuoto
bool Position::Check_lenght(Coordinates c){
    current_position = mvwinch(curwin, c.getY(), c.getX());
    if(current_position == ' ') return true;
    else return false;
}

//Ritorna true se c'è il player
bool Position::Check_Player(Coordinates c){
    current_position = mvwinch(curwin, c.getY(), c.getX());
    if(current_position == '@') return true;
    else return false;
}

//Ritorna true se c'è il nemico
bool Position::Check_enemies(Coordinates c){
    current_position = mvwinch(curwin, c.getY(), c.getX());
    if(current_position == '#' || current_position == '&' || current_position == '%')
    return true;
    else return false;
}