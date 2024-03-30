//created by Luca Panariello 
#include "TreeRoom.hpp"

TreeRoom::TreeRoom(){}

TreeRoom::TreeRoom (Room start, ArtefactHandler AH, EnemiesHandler EH) {
        this->T=generate_tree(start,-1,T,AH,EH);
}

int TreeRoom::opposite(int i){
      if (i<2) {return i+2;} else {return i-2;}
}

Tree* TreeRoom::generate_tree(Room room, int direction, Tree* N, ArtefactHandler AH, EnemiesHandler EH){
      N=new Tree;
      N->R=room;
      N->AH=AH;
      N->EH=EH;
      int o = opposite(direction);
      for (int i=0;i<4;i++){
            //direction==-1 quando si è nella stanza iniziale quindi 
            //non si è entrati da nessuna parte
            if (direction!=-1 && i==o) {N->D[i]=this->T;} else {N->D[i]=NULL;}
      }
      return N;
};

void TreeRoom::insert(Room room, int direction, ArtefactHandler AH, EnemiesHandler EH) {
      Tree* N;
      //Collego la stanza da cui sono uscito a quella appena creata;
      N=generate_tree(room,direction,N,AH,EH);
      this->T->D[direction]=N;
      this->T=N;
}

void TreeRoom::move (int direction) {
      if (this->T->D[direction]!=NULL) {this->T=this->T->D[direction];}
}

Room TreeRoom::current_room() {
      return T->R;
}

Tree* TreeRoom::get_tree_direction(int d){
      return T->D[d];
}

ArtefactHandler TreeRoom::getAH(){
      return T->AH;
}

EnemiesHandler TreeRoom::getEH(){
      return T->EH;
}

void TreeRoom::unlock(){
      this->T->R.unlock();      
}

Artefact TreeRoom::RemoveArtefact(char A, Coordinates C){
      return this->T->AH.RemoveArtefact(A,C);
}

int TreeRoom::RemoveEnemy(int damage,Coordinates C){
      return this->T->EH.RemoveEnemy(damage,C);
}

int TreeRoom::EnemyPhase(Coordinates PlayerC){
      return this->T->EH.EnemyChoise(PlayerC);
}

void TreeRoom::showEnemies(){
      this->T->EH.PrintEnemy();
}