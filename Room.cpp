//created by Luca Panariello 
#include "Room.hpp"

Room::Room(int ly, int lx, int entrance, WINDOW* play,bool from_door, bool first_room){
    this->room_win=play;
    this->length=Coordinates(lx,ly);
    this->entrance=entrance;
    this->first_room=first_room;
    bool E[4];
    srand(time(0));
    
    //la prima stanza ha solo un'uscita
    //oppure se sono appena entrato da una porta, la stanza avra una sola uscita
    //per non creare troppe porte
    if (first_room || from_door){n_exit=1;}
    //numero di uscite casuale
    else {this->n_exit=(rand()%2)+1;}

    this->exit=Exits(' ',length.getX(),length.getY(),room_win);
    //impostiamo le Uscite
    this->exit.build(this->entrance,n_exit,this->first_room);   
    this->exit.getArray(E);
    //impostiamo le Porte - X
    this->door=Doors('X',length.getX(),length.getY(),room_win);
    this->door.build(n_exit,this->entrance,E,this->first_room); 
    this->has_door=door.getHasDoor();
    //impostiamo i Muri
    this->wall=Walls(E,length.getY(),length.getX(),play,this->first_room);  
}

Walls Room::getWalls(){
    return this->wall;
}

void Room::print_room(){
    box(room_win,0,0);
    exit.print();
    if (this->has_door) {door.print();}
    wall.print();
}

Exits Room::get_Exit(){
    return this->exit;
}

Doors Room::get_Doors(){
    return this->door;
}

WINDOW* Room::getScreen(){
    return this->room_win;
}

void Room::unlock(){
    this->has_door=false;
}