//created by Giulia Torsani

#include "Player.hpp"

Player::Player(WINDOW* curwin,Coordinates coords, char c,int pv, int damage, int score, int lvl, bool isdead, int KeyCounter, bool Shield, bool Coat, int Bullets, bool Weapon) 
: Entity (curwin,coords, c, pv, damage, score, lvl, isdead){
    this->KeyCounter=KeyCounter;
    this->Shield=Shield;
    this->Coat=Coat;
    this->Bullets=Bullets;
    this->InGlass=false;
}


int Player::getKeys(){
    return KeyCounter;
}
    
void Player::editKeys(int key){
    KeyCounter= KeyCounter+key;
}

bool Player::hasShield(){
    return Shield;
}

bool Player::hasCoat(){
    return Coat;   
}
    
void Player::editCoat(){
    Coat = !Coat;
}

void Player::editShield(){
    Shield = !Shield;
}

int Player::getBullets(){
    return Bullets;
}

void Player::editBullets(int bul){
    Bullets = Bullets+bul;
}



void Player::getartefact(Artefact A){
    char type;
    int points = (Player::getscore() + A.getScore());
    Player::setscore(points);
    type = A.getType();
    if(type=='H'){
        Player::editpv(10);
    }
    else if(type=='C'){
        if(!Player::hasCoat()){
            Player::editCoat();
        }
    }
    else if(type == 'K'){
        Player::editKeys(1);
    }
    else if (type == 'B'){          //bullets, raccolti a gruppi di 10
        Player::editBullets(10);
    }
    else if(type=='S'){
         if(!Player::hasShield()){
            Player::editShield();
        }
    } else if (type == 'A'){          //aumenta la vita massima di 10
        maxLife=maxLife+10;
    }
}

bool Player::isinglass(){
    return this->InGlass;
};

void Player::editInGlass(){
    InGlass=!InGlass;
}

void Player::levelmanager(){
        int points = Entity::getscore();
        int curlvl = Entity::getLevel();
        int tmp;

        if(curlvl>=0 && curlvl<=2){
            tmp=points/150;
            Player::setLevel(tmp);
        }
        else if(curlvl>2 && curlvl<=7){
            //sottraggo i punti del range precedente,
            //eseguo il calcolo con la nuova soglia e risommo i livelli già acquisiti
            tmp=(points-450)/200;
            Player::setLevel(tmp+3);
        }
        else if(curlvl>7 && curlvl<=12){
            tmp=(points-1450)/250;
            Player::setLevel(tmp+8);
        }
        else{
            tmp=(points-2700)/300;
            Player::setLevel(tmp+13);
        }
}



