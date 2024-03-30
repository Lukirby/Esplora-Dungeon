//created by Luca Panariello
#include "Doors.hpp"

Doors::Doors(){}

Doors::Doors(char c,int startx, int starty, WINDOW* room):Exits(c,startx,starty,room){}


void Doors::build(int n_exit, int entrance, bool E[],bool first){
    this->has_door=false;
    this->where_is_door=-1;
    //creo una porta nel caso la stanza non sia la prima a essere generata e
    //Ho ben due uscite (una di essere sarà bloccata da una porta)
    if (!first && n_exit==2){   
        //riempo l'array con le uscite possibili     
        int C[n_exit]; int e=0;
        for (int i=0; e<n_exit; i++){
            if (i!=entrance && E[i]) {C[e]=i; e++;}
        }
        int k=rand()%n_exit;
        //selezione casualmente un uscita da rendere porta
        this->E[C[k]]=true;
        this->has_door=true;
        this->where_is_door=C[k];
    }
}

bool Doors::getHasDoor(){
    return has_door;
}

int Doors::getWhereIsDoor(){
    return where_is_door;
}