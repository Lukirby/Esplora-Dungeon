//created by Federica Santisi
#include "Movement2.hpp"

//Versione Finale

Movements::Movements(WINDOW* curwin,int x, int y):Coordinates(x,y){
    this -> cont = 0; //Cambio cont -> 0
    this -> check = true;
    this -> xp = 0; this -> xe = 0;
    this -> yp = 0; this -> ye = 0;
    this -> I = Interaction(Coordinates(50,26),Coordinates(0,0),'0',curwin);
}

/*Movimento verticale del nemico che si muove nel momento in cui si muove il giocatore
controllando di muoversi in zone consentite (non va al di fuori della stanza e
non attraversa muri
*/
Coordinates Movements::move_y(Coordinates C){
    Coordinates newCursor=C;
    if(check){
        newCursor.decreaseY();
        I.setCursor(newCursor);
        if(!I.checkWalls() && !I.checkSpecialWalls() && !I.checkBorder(0)) C.decreaseY();
        cont ++;
        if (cont>4) check=false;
    } else {
        newCursor.increaseY();
        I.setCursor(newCursor);
        if(!I.checkWalls() && !I.checkSpecialWalls() && !I.checkBorder(2)) C.increaseY();
        cont--;
        if (cont<1) check=true;

    }
    return C;
}

/*Movimento orizzontale del nemico che si muove nel momento in cui si muove il giocatore
controllando di muoversi in zone consentite (non va al di fuori della stanza e
non attraversa muri
*/
Coordinates Movements::move_x(Coordinates C){
    Coordinates newCursor=C;
    if(check){
        newCursor.increaseX();
        I.setCursor(newCursor);
        if(!I.checkWalls() && !I.checkSpecialWalls() && !I.checkBorder(1)) C.increaseX();
        cont ++;
        if (cont>4) check=false;
    } else {
        newCursor.decreaseX();
        I.setCursor(newCursor);
        if(!I.checkWalls() && !I.checkSpecialWalls() && !I.checkBorder(3)) C.decreaseX();
        cont--;
        if (cont<1) check=true;

    }
    return C;
}

/*Movimento orizzontale del nemico  da muro a muro che si muove nel momento in cui si 
muove il giocatore controllando di muoversi in zone consentite (non va al di fuori della stanza e
non attraversa muri
*/
Coordinates Movements::Hit_walls_x(Coordinates C){
    Coordinates newCursor=C;
    if(check){
        newCursor.decreaseX();
        I.setCursor(newCursor);
        if(I.checkWalls() || I.checkSpecialWalls() || I.checkBorder(3)){
        check = false;
        } else {C.decreaseX();}
    }else{
        newCursor.increaseX();
        I.setCursor(newCursor);
        if(I.checkWalls() || I.checkSpecialWalls() || I.checkBorder(1)){
        check = true;
        } else {C.increaseX();}
    }
    return C;   
}

/*Movimento orizzontale del nemico  da muro a muro che si muove nel momento in cui si 
muove il giocatore controllando di muoversi in zone consentite (non va al di fuori della stanza e
non attraversa muri
*/
Coordinates Movements::Hit_walls_y(Coordinates C){
    Coordinates newCursor=C;
    if(check){
        newCursor.decreaseY();
        I.setCursor(newCursor);
        if(I.checkWalls() || I.checkSpecialWalls() || I.checkBorder(0)){
        check = false;
        } else {C.decreaseY();}
    }else{
        newCursor.increaseY();
        I.setCursor(newCursor);
        if(I.checkWalls() || I.checkSpecialWalls() || I.checkBorder(2)){
        check = true;
        } else {C.increaseY();}
    }
    return C;   
}

/*Movimento di inseguimento del giocatore in cui viene scelta la direzione in cui muoversi
in base alla posizione del player, in modo tale da avvicinarsi sempre di più
*/
Coordinates Movements::Chase_Player(Coordinates EnemyC, Coordinates PlayerC){
    xp = PlayerC.getX(); xe = EnemyC.getX(); Coordinates newCursor=EnemyC;
    yp = PlayerC.getY(); ye = EnemyC.getY();
    if((abs(xp-xe) < abs(yp - ye) && xe!=xp) || yp == ye){
        if(xp < xe) {
            newCursor.decreaseX();
            I.setCursor(newCursor);
            if(!I.checkWalls() && !I.checkSpecialWalls() && !I.checkBorder(3)) EnemyC.decreaseX();}
        else {
            newCursor.increaseX();
            I.setCursor(newCursor);
            if(!I.checkWalls() && !I.checkSpecialWalls() && !I.checkBorder(1)) EnemyC.increaseX();
            }
    }else{
        if(yp < ye) {
            newCursor.decreaseY();
            I.setCursor(newCursor);
            if(!I.checkWalls() && !I.checkSpecialWalls() && !I.checkBorder(0)) EnemyC.decreaseY();}
        else {
        newCursor.increaseY();
        I.setCursor(newCursor);
        if(!I.checkWalls() && !I.checkSpecialWalls() && !I.checkBorder(2)) EnemyC.increaseY();
        }
    }
    return EnemyC;
}