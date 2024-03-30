//created by Luca Panariello 
#include "Interaction.hpp"

Interaction::Interaction(Coordinates max, Coordinates cursor, char c, WINDOW* curwin){
    this->max=max;
    this->cursor=cursor;
    this->c=c;
    this->curwin=curwin;
    this->Border[0]=0;
    this->Border[1]=this->max.getX();
    this->Border[2]=this->max.getY();
    this->Border[3]=0;
}

char Interaction::readChar(){
    return mvwinch(curwin,cursor.getY(),cursor.getX());
}

bool Interaction::checkWalls(){
    c=readChar();
    if (c!=' ') {return true;} else {return false;}
} //controlla che ci sia un muro o qualche altro ostacolo

bool Interaction::checkExits(){
    c=readChar();
    if (c==' '){return true;} else {return false;}
}

bool Interaction::checkBorder(int i){
    switch (i)
    {
        case 0:
        return cursor.getY()==this->Border[0];
        break;
        case 1:
        return cursor.getX()==this->Border[1]-1;
        break;
        case 2:
        return cursor.getY()==this->Border[2]-1;
        break;
        case 3:
        return cursor.getX()==this->Border[3];
        break;
        default:
        break;
    }
    return false;
}

bool Interaction::checkArtefact(){
    c=readChar();
    switch(c){
        case 'H':
        return true;
        break;
        
        case 'K':
        return true;
        break;
        
        case 'G':
        return true;
        break;
        
        case 'B':
        return true;
        break;
        
        case 'C':
        return true;
        break;
        
        case 'S':
        return true;
        break;

        case 'A':
        return true;
        break;

        default:
        return false;
        break;
    }
}

bool Interaction::checkDoors(){
    c=readChar();
    return c=='X';
}


bool Interaction::checkSpecialWalls(){
    c=readChar();
    //Vedere Classe Walls per dettagli
    return c=='a';
}

bool Interaction::checkEnemy(){
    c=readChar();
    switch(c){
        case '#':
        return true;
        break;
        
        case '%':
        return true;
        break;

        case '&':
        return true;
        break;

        default:
        return false;
        break;
    }
}

int Interaction::checkInSight(int d){
    bool b=false;
    while(!b){
        switch(d){
            case 0:
                cursor.decreaseY();
             break;
            case 1:
                cursor.increaseX();
            break;
            case 2:
                cursor.increaseY();
            break;
            case 3:
                cursor.decreaseX();
            break;
        }
        if (checkWalls() || checkBorder(d)){b=true;}
    }
    if (c=='@'){return d;} else {return -1;}
}

int Interaction::CheckPlayerSight(Coordinates PlayerC){
    int direction = -1;
    if (cursor.getX()==PlayerC.getX()){
        if (cursor.getY()>PlayerC.getY()){
            return checkInSight(0);
        } else {
            return checkInSight(2);
        }
    } else 
    if (cursor.getY()==PlayerC.getY()){
        if (cursor.getX()<PlayerC.getX()){
            return checkInSight(1);
        } else {
            return checkInSight(3);
        }
    } else {return -1;}
}

bool Interaction::checkPlayerNextEnemy(Coordinates PlayerC){
    if (cursor.getX()==PlayerC.getX()){
        if (cursor.getY()>PlayerC.getY()){
            cursor.decreaseY();
        } else {
            cursor.increaseY();
        }
    } else 
    if (cursor.getY()==PlayerC.getY()){
        if (cursor.getX()<PlayerC.getX()){
            cursor.increaseX();
        } else {
            cursor.decreaseX();
        }
    }
    return cursor.sameCoordinates(PlayerC);
}

void Interaction::setCursor(Coordinates c){
    this->cursor=c;
}