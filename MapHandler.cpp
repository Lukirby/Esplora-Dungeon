//created by Luca Panariello 

#include "MapHandler.hpp"

MapHandler::MapHandler(){}

MapHandler::MapHandler(int xMax, int yMax,Coordinates max, Coordinates cursor, char c, WINDOW* curwin):Interaction( max, cursor, c, curwin){
   this->M=Map((xMax/2)-25,8);
   this->curwin=this->M.get_screen();
   this->P=Player(M.get_screen(),cursor,'@',100,10,0,0,false,0,false,false,10,false);
   this->P.display();
   wrefresh(this->curwin);
   this->direction=10;
   this->G=Gamestate();
}

void MapHandler::get_action(int c){
   switch(c){
   case (int)'w':
      this->action=-1;
   break;
   
   case (int)'d':
      this->action=-2;
   break;

   case (int)'s':
      this->action=-3;
   break;

   case (int)'a':
      this->action=-4;
   break;
   case 64: //ASCII Barra Spaziatrice: 32
      this->action=-100; //PAUSA
   break;
   default:
      this->action=777;
   break;
   }
}

void MapHandler::get_direction(){
   int c=wgetch(this->curwin);
   switch (c)
   {
   case KEY_UP:
      this->direction=0;
   break;
   
   case KEY_RIGHT:
      this->direction=1;
   break;

   case KEY_DOWN:
      this->direction=2;
   break;
   case KEY_LEFT:
      this->direction=3;
   break;      
   default:
      this->direction=10;
      if (c<'a') {c=c+32;}
      get_action(c);
   break;
   }
}

void MapHandler::next_position(){
   //imposta la prossima posizione del cursore NOTA: senza muovere il personaggio
   this->cursor=P.getCoordinates(); int direction_or_action;
   if (this->direction==10){
      direction_or_action=abs(this->action)-1;
   } else {direction_or_action=this->direction;}
   switch(direction_or_action){
      case 0:
         this->cursor.decreaseY(1);
      break;
      
      case 1:
         this->cursor.increaseX(1);
      break;
      
      case 2:
         this->cursor.increaseY(1);
      break;
         
      case 3:
         this->cursor.decreaseX(1);
      break;

      default:
      break;
   }
}

//teletrasporta il giocatore nella stanza successiva
void MapHandler::warpPlayer(){
   switch (this->direction){
      case 0:
         this->cursor.increaseY(24);
         this->P.setCoordinates(this->cursor);
      break;

      case 1:
         this->cursor.decreaseX(48);
         this->P.setCoordinates(this->cursor);
      break;

      case 2:
         this->cursor.decreaseY(24);
         this->P.setCoordinates(this->cursor);
      break;
      
      case 3:
         this->cursor.increaseX(48);
         this->P.setCoordinates(this->cursor);
      break;
      
      default:
      break;
   }
}

bool MapHandler::miniWarp(){
   switch (this->direction){
      case 0:
         this->cursor.decreaseY(1);
         //controllo che il punto di "teletrasporto" non sia un ostacolo
         if (!Interaction::checkWalls()) {this->P.setCoordinates(this->cursor); return true;}
         else this->cursor.increaseY(1); return false;
      break;
      
      case 1:
         this->cursor.increaseX(1);
         if (!Interaction::checkWalls()) {this->P.setCoordinates(this->cursor); return true;}
         else this->cursor.decreaseX(1); return false;
      break;
      
      case 2:
         this->cursor.increaseY(1);
         if (!Interaction::checkWalls()) {this->P.setCoordinates(this->cursor); return true;}
         else this->cursor.decreaseY(1); return false;
      break;
      
      case 3:
         this->cursor.decreaseX(1);
         if (!Interaction::checkWalls()) {this->P.setCoordinates(this->cursor); return true;}
         else this->cursor.increaseX(1); return false;
      break;
      
      default:
         return false;
      break;
   }
}

void MapHandler::KillEnemy(Coordinates C,int damage){
   int newscore=P.getscore()+M.RemoveEnemy(damage,C);
   //il giocatore raccoglie il punteggio derivante dalla morte del nemico
   P.setscore(newscore);
   Display();
}

bool MapHandler::PlayerRawAttack(){
   if (Interaction::checkEnemy()){
      KillEnemy(cursor,P.getdamage()*2);
      return true;
   } else {return false;}
}

void MapHandler::PlayerShot(){
   P.Entity::setShoot();
   if(P.getBullets()>0){
      //uso un proitettile
      P.editBullets(-1);
      Coordinates Hit_Enemy=Coordinates(-1,-1);
      switch(this->action){
         case -1:
            Hit_Enemy=P.Entity::useShoot().Shoot_up();
         break;
         case -2:
            Hit_Enemy=P.Entity::useShoot().Shoot_right();
         break;
         case -3:
            Hit_Enemy=P.Entity::useShoot().Shoot_down();
         break;
         case -4:
            Hit_Enemy=P.Entity::useShoot().Shoot_left();
         break;
         default:
            //"recupero" il proitettile in caso non decida di sparare
            P.editBullets(1);
         break;
      }
      if (Hit_Enemy.getX()!=-1){
         KillEnemy(Hit_Enemy,P.getdamage());
      }
   }
}

void MapHandler::PlayerAction(){
   //controllo se vi è la possibilità di attaccare ravvicinatamente
   if (!PlayerRawAttack()){PlayerShot();}
}

bool MapHandler::CheckScene(){
   //controllo se vi sono le condizioni per cambiare stanza e ritorno un booleano in caso favorevole
   if (Interaction::checkBorder(this->direction) && Interaction::checkExits()){
      return true;
   } else {return false;}
}  

void MapHandler::ChangeScene(){
   //effettivo cambio della stanza in caso favorevole
   if (CheckScene()) {
      //ottengo del punteggio extra ogni volta che scopro una nuova stanza
      if (this->M.explore(this->direction,P.getLevel())){P.setscore(P.getscore()+20);}
      warpPlayer();
   }
}  

void MapHandler::PickArtefact(){
   //controlla se vi è un artefatto e nel caso lo raccoglie
   if (Interaction::checkArtefact()){
      Artefact A=M.RemoveArtefact(c,cursor);
      P.getartefact(A);
      P.getmv(direction);
   }
}

void MapHandler::UnlockDoors(){
   if (Interaction::checkDoors() && P.getKeys()>0){
      P.editKeys(-1);
      M.unlock();
      M.reload();
   }
}

void MapHandler::BeyondWalls(){
   //controllo se sono in prossimità di un muro speciale e sono in possesso
   //del mantello cloak C, in caso positivo mi "teletrasporto" nei muri speciali
   if (Interaction::checkSpecialWalls() && P.hasCoat()){
      if (miniWarp()){
         //se sono già dentro ai muri una volta uscito il cloak C si esaurisce
         if (P.isinglass()){P.editCoat();}
         P.editInGlass();
         M.reload();
      }
   }
}

void MapHandler::PlayerMovement(){
   PickArtefact();                           
   UnlockDoors();                            
   if (!Interaction::checkWalls()) {P.getmv(direction);}  
   ChangeScene();                            
   BeyondWalls();
}

void MapHandler::EnemyPhase(){
   int damage = M.EnemyPhase(P.getCoordinates());
   if (damage!=0 && P.hasShield()){P.editShield();}
   else {P.editpv(-damage);}
}

void MapHandler::Display(){
   M.reload();
   G.ShowState(P);
   P.display();
   wrefresh(curwin);                         //Aggiorna lo Schermo
}

bool MapHandler::PlayerDeath(){
   this->P.checkisdead();
   return P.getisdead();
}

void MapHandler::PlayGame(){
   Display();                                   
   wrefresh(curwin);
   this->action=10;                             //Entra nel Loop dopo la Pausa
   do{
      get_direction();                          //prende in input la direzione in cui ci vogliamo muovere
      next_position();                          
      if (this->direction!=10){
         PlayerMovement();                      //Player si Muove
      } else {
         PlayerAction();                        //Player Esegue un Azione
      }
      P.levelmanager();                         //Aggiorna il Livello del Giocatore
      Display();
      if (this->action!=-100) {EnemyPhase();}   //Fase Nemico - Non viene eseguita se si imposta la pausa
      Display();
      if (PlayerDeath()){this->action=-100;}
   }while(this->action!=-100);                  //GIOCO CONTINUO fino alla Pausa
}

void MapHandler::CloseGame(){
   werase(curwin);
   wrefresh(curwin);
   delwin(curwin);
   G.~Gamestate();                              //Uso del Distruttore per Deallocare la Memoria
}