//created by Luca Panariello
#include "Exits.hpp"



Exits::Exits(){}

Exits::Exits(char c, int startx, int starty, WINDOW* room){
        this->c=c;
        this->room=room;
        //inizializzo le uscite
        for (int i=0; i<4; i++){           
            this->E[i]=false;
        }
        this->start=Coordinates(startx,starty);
}

void Exits::build(int entrance, int n_exit,bool first){
    //deve esserci per forza un uscita che corrisponde con l'entrata
    this->E[entrance]=true;
    if (!first){                           
        int C[3];                        
        int e=0;
        //riempo l'array con le possibili uscite non ancora utilizzate
        for (int i=0; e<3; i++){           
            if (i!=entrance){C[e]=i;e++;}
        }
        int k=3; int a;
        //imposto le uscite mancanti casualmente
        //sposto in fondo all'Array le uscite "scelte" e riduco
        //l'intervallo di uscite tra cui scegliere
        for (int n=n_exit; n>0; n--){      
            a=rand()%k;
            this->E[C[a]]=true;
            C[a]=C[k-1];
            k--;
        }
    }
}

void Exits::print(){
    if (this->E[0]){ for (int i=-1; i<2;i++) {mvwaddch(room,0,((start.getX()-1)/2)+i,c);}}
    if (this->E[1]){ for (int i=-1; i<2;i++) {mvwaddch(room,((start.getY()-1)/2)+i,start.getX()-1,c);}}
    if (this->E[2]){ for (int i=-1; i<2;i++) {mvwaddch(room,start.getY()-1,((start.getX()-1)/2)+i,c);}}        
    if (this->E[3]){ for (int i=-1; i<2;i++) {mvwaddch(room,((start.getY()-1)/2)+i,0,c);}}
}

void Exits::getArray(bool S[]){
    for (int i=0; i<4; i++){
        S[i]=this->E[i];
    }
}