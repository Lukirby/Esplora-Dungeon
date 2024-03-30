//created by Luca Panariello 
#include "SpawnPoints.hpp"

SpawnPoints::SpawnPoints(){
    for (int i=0; i<4; i++){
        this->SP[i]=LoC();
    }
    this->stx=50; this->sty=26;
}

void SpawnPoints::build(Room R, bool first_room){
    //Ottengo delle Coordnate solo se la stanza non è la prima a essere generata
    if (!first_room){
        Walls W=R.getWalls(); 
        //Costruttore Copia che ci Indica dove si Trova la Porta
        int door=R.get_Doors().getWhereIsDoor();
        Coordinates E; Coordinates A; int sp;
        E=Coordinates(0,0); A=Coordinates(0,0);

        if (W.getWall(0)!=0 && W.getWall(0)!=2) {
            if (W.getWall(0)==1 && door!=0) {E.setX((stx-1)/2);E.setY(4); this->SP[0].insert_c(E);sp=2;} 
            else if (W.getWall(0)==1) {E.setX((stx-1)/2);E.setY(4); this->SP[1].insert_c(E);sp=2;}
            else {sp=3;}
            A.setX((stx-1)/2);A.setY(2);
            this->SP[sp].insert_c(A);
        } 
    
        if (W.getWall(1)!=0 && W.getWall(1)!=2){
            if (W.getWall(1)==1 && door!=1) {E.setX(stx-9);E.setY((sty-1)/2); this->SP[0].insert_c(E);sp=2;} 
            else if (W.getWall(1)==1) {E.setX(stx-9);E.setY((sty-1)/2); this->SP[1].insert_c(E);sp=2;}
            else {sp=3;}
            A.setX(stx-5);A.setY((sty-1)/2);
            this->SP[sp].insert_c(A);
        }  

        if (W.getWall(2)!=0 && W.getWall(2)!=2){
            if (W.getWall(2)==1 && door!=2) {E.setX((stx-1)/2);E.setY(sty-5); this->SP[0].insert_c(E);sp=2;} 
            else if (W.getWall(2)==1) {E.setX((stx-1)/2);E.setY(sty-5); this->SP[1].insert_c(E);sp=2;}
            else {sp=3;}
            A.setX((stx-1)/2);A.setY(sty-3);
            this->SP[sp].insert_c(A);
        } 

        if (W.getWall(3)!=0 && W.getWall(3)!=2){
            if (W.getWall(3)==1 && door!=3) {E.setX(8);E.setY((sty-1)/2); this->SP[0].insert_c(E);sp=2;}
            if (W.getWall(3)==1) {E.setX(8);E.setY((sty-1)/2); this->SP[1].insert_c(E);sp=2;} 
            else {sp=3;}
            A.setX(4);A.setY((sty-1)/2);
            this->SP[sp].insert_c(A);
        }   

        if (W.getWall(4)==2) {E.setX((stx-1)/2); E.setY(((sty-1)/2)+3); A.setX((stx-1)/2);A.setY(((sty-1)/2)-2);
            this->SP[1].insert_c(E); this->SP[1].insert_c(A);
        }   

        if (W.getWall(5)==2) {E.setX(((stx-1)/2)+6);E.setY((sty-1)/2); A.setX(((stx-1)/2)-6);A.setY((sty-1)/2);
            this->SP[1].insert_c(E); this->SP[1].insert_c(A);
        }    
    
        if (W.getWall(6)!=0){A.setX(8);A.setY(4);
            if (W.getWall(6)==1){E.setX(8);E.setY(6); this->SP[1].insert_c(E);this->SP[2].insert_c(A);}
            else {this->SP[3].insert_c(A);}
        }   

        if (W.getWall(7)!=0){A.setX(stx-9); A.setY(4); 
            if (W.getWall(7)==1) {E.setX(stx-9);E.setY(6); this->SP[1].insert_c(E);this->SP[2].insert_c(A);}
            else {this->SP[3].insert_c(A);}
        }   
    
    
        if (W.getWall(8)!=0){A.setX(stx-9); A.setY(((sty-1)/2)+8); 
            if (W.getWall(8)==1) {E.setX(stx-9); E.setY(((sty-1)/2)+6); this->SP[1].insert_c(E);this->SP[2].insert_c(A);}
            else {this->SP[3].insert_c(A);}
        }   


        if (W.getWall(9)!=0){A.setX(8); A.setY(((sty-1)/2)+8); 
            if (W.getWall(9)==1) {E.setX(8); E.setY(((sty-1)/2)+6); this->SP[1].insert_c(E);this->SP[2].insert_c(A);}
            else {this->SP[3].insert_c(A);}
        } 
    
    
        if (W.getWall(10)==1){
            E.setX((stx-1)/2); E.setY(((sty-1)/2)-4); A.setX(((stx-1)/2)-9); A.setY((sty-1)/2);
            this->SP[1].insert_c(E); this->SP[1].insert_c(A);
            E.setX((stx-1)/2); E.setY(((sty-1)/2)+4); A.setX(((stx-1)/2)+9); A.setY((sty-1)/2);
            this->SP[1].insert_c(E); this->SP[1].insert_c(A);
        }   
    
        if (W.getWall(4)==1 || W.getWall(5)==1 || W.getWall(10)==1 || W.getWall(10)==3){
            E.setX((stx-1)/2); E.setY((sty-1)/2);
            if (W.getWall(10)==1) {this->SP[2].insert_c(E);} else
            if (W.getWall(10)==3) {this->SP[3].insert_c(E);} else {this->SP[0].insert_c(E);}
        }   
    }
}

Coordinates SpawnPoints::extract(int sp){
    srand(time(0));
    //nel caso non ci siano più spawnpoint in una lista, passo a estrarli nell'altra lista complementare
    if (SP[sp].get_length()==0 && sp==3){sp--;} else if (SP[sp].get_length()==0 && sp==2) {sp++;}
    if (SP[sp].get_length()==0 && sp==1){sp--;} else if (SP[sp].get_length()==0 && sp==0) {sp++;}
    int n=(rand()%SP[sp].get_length())+1;
    return this->SP[sp].delete_c(n);
}

int SpawnPoints::get_nArtefact(){
    int n=SP[2].get_length()+SP[3].get_length();
    if (n>3) {return 3;} else {return n;}
    //max 3 artefatti per stanza
}

int SpawnPoints::get_nEnemies(){
    int n=SP[0].get_length()+SP[1].get_length();
    if (n>3) {return 3;} else {return n;}
    //max 3 nemici per stanza
}