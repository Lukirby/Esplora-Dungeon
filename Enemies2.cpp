//created by Federica Santisi
#include "Enemies2.hpp"

Enemy::Enemy(WINDOW* curwin,Coordinates coords, char c, int pv, int damage, int score, int lvl,
bool isdead, int move, int shoot, bool just_shoot, bool armed):Entity(curwin,coords,c,pv,damage,score,lvl,isdead){
    this -> move = move;
    this -> just_shoot = just_shoot;
    this -> armed = armed;
    this -> M = Movements (curwin,0,0);
    this -> CP = CheckPlayer (curwin);
    this -> shoot = shoot;
}

//Ritorna il tipo di movimento
int Enemy::Is_move(){
    return move;
    }

//Ritorna la direzione di sparo
int Enemy::Is_shooting(){
    return shoot;
    }

//Ritorna true se è armato, false altrimenti
bool Enemy::Is_armed(){
    return armed;
}

/*Questo metodo associa all'int ritornato da move un movimento in particolare e aggiorna
le coordinate del nemico con quelle dopo il movimento
*/
void Enemy::Moving(Coordinates PlayerC){
    Coordinates C;
    switch(this->move){
        case 0:
        break;
        case 1:
            C=M.move_x(coordinates);
            coordinates=C;
        break;
        case 2:
            C=M.move_y(coordinates);
            coordinates=C;
        break;
        case 3:
            C=M.Hit_walls_x(coordinates);
            coordinates=C;        
        break;
        case 4:
            C=M.Hit_walls_y(coordinates);
            coordinates=C;      
        break;
        case 5:
            C=M.Chase_Player(coordinates,PlayerC);
            coordinates=C;
        break;
    }
}

/*Questo metodo associa all'int ritornato da shoot un tipo di sparo in particolare e salva
le coordinate dell'ultimo proiettile stampato in modo che se esse coincidono con le coordinate
del Player allora lo sparo ha recato danno al giocatore
*/
int Enemy::Shooting(Coordinates PlayerC){
    int d; int r;
    S.Set_Coordinates(coordinates); Coordinates hit;
    srand(time(0));
    switch(this->shoot){
        case 0:
        break;
        case 1:
            r=rand()%4+1;
            switch (r){
                case 1:
                    hit=S.Shoot_up();
                break;
                case 2:
                    hit=S.Shoot_right();
                break;
                case 3:
                    hit=S.Shoot_down();
                break;
                case 4:
                    hit=S.Shoot_left();
                break;
            }
        break;
        case 2:
            d = CP.Check_Player_In_Sight(coordinates,PlayerC);
            switch (d)
            {
            case 0:
            hit=S.Shoot_up();
            break;
            case 1:
            hit=S.Shoot_right();
            break;
            case 2:
            hit=S.Shoot_down();
            break;
            case 3:
            hit=S.Shoot_left();
            break;
            default:
            hit=Coordinates(-1,-1);
            break;
            }
        break;
    }
    if (hit.sameCoordinates(PlayerC)) return this->damage;
    else return 0;
}

int Enemy::Armed(Coordinates PlayerC){
    Coordinates C=coordinates;
    if (CP.Check_Player_next_to_Enemy(C,PlayerC) && this->armed){
        return this->damage;}
    else return 0; 
}
/*
*/