//created by Luca Panariello
#include "CheckPlayer.hpp"

CheckPlayer::CheckPlayer(WINDOW* win){
    this->I=Interaction(Coordinates(50,26),Coordinates(0,0),'0',win);
}

int CheckPlayer::Check_Player_In_Sight(Coordinates EnemyC, Coordinates PlayerC){
    this->I.setCursor(EnemyC);
    return this->I.CheckPlayerSight(PlayerC);
}

bool CheckPlayer::Check_Player_next_to_Enemy(Coordinates EnemyC, Coordinates PlayerC){
    this->I.setCursor(EnemyC);
    return this->I.checkPlayerNextEnemy(PlayerC);
}