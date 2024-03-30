//created by Federica Santisi 
#include "Shooter.hpp"
Shooter::Shooter(){}

Shooter::Shooter(WINDOW *curwin, Coordinates c){
    this -> bv = '|';
    this -> bh = '-';
    this -> wait = 60;
    this -> wait2 = 35;
    this -> found = false;
    for(int i=1; i<4; i++){
        this -> TypeShoot[i] = i;
    }
    this -> curwin = curwin;
    this -> c = c; 
    this -> p = Position(curwin);
}

/* Tutte le funzioni di sparo vengono gestite tramite la gestione delle coordinate del 
char " - " che abbiamo identificato come proiettile.
In particolare viene stampato il proiettile fino a quando check_lenght = false (ovvero
viene trovato un' ostacolo)
Quando trovo un ostacolo mi serve identificare se esso corrisponde al giocatore o al nemico
oppure ho semplicemente incontrato un muro speciale, o un bordo, ecc ...
*/

Coordinates Shooter::Shoot_up(){
    Coordinates start=c;
    c.decreaseY(1);
    while(p.Check_lenght(c)){
    mvwaddch(curwin, c.getY(), c.getX(),bv);
    wrefresh(curwin);                 
    delay_output(wait);         //funzione che rallenta la stampa del proiettile
    mvwaddch(curwin, c.getY(), c.getX(),' ');
    c.decreaseY(1);
    }
    if(p.Check_Player(c)) found = true;
    else if(p.Check_enemies(c)) found =  true;
    else found = false;
    if (!found) {c.setX(-1);c.setY(-1);}
    return c;
}

Coordinates Shooter::Shoot_down(){
    Coordinates start = c;
    c.increaseY(1);
    while(p.Check_lenght(c)){
    mvwaddch(curwin, c.getY(), c.getX(),bv);
    wrefresh(curwin);
    delay_output(wait);
    mvwaddch(curwin, c.getY(), c.getX(), ' ');
    c.increaseY(1);
    }
    if(p.Check_Player(c)) found = true;
    else if(p.Check_enemies(c)) found =  true;
    else found = false;
    if (!found) {c.setX(-1);c.setY(-1);}
    //c=start;
    return c;
}

Coordinates Shooter::Shoot_left(){
    Coordinates start = c;
    c.decreaseX(1);
    while(p.Check_lenght(c)){
        mvwaddch(curwin, c.getY(), c.getX(),bh);
        wrefresh(curwin);
        delay_output(wait2);
        mvwaddch(curwin, c.getY(), c.getX(), ' ');
        c.decreaseX(1);
    }
    if(p.Check_Player(c)) found = true;
    else if(p.Check_enemies(c)) found =  true;
    else found = false;
    if (!found) {c.setX(-1);c.setY(-1);}
    //c=start;
    return c;
}

Coordinates Shooter::Shoot_right(){
   Coordinates start = c;
    c.increaseX(1);
    while(p.Check_lenght(c)){
        mvwaddch(curwin, c.getY(), c.getX(),bh);
        wrefresh(curwin);
        delay_output(wait2);
        mvwaddch(curwin, c.getY(), c.getX(), ' ');
        c.increaseX(1);
    }
    if(p.Check_Player(c)) found = true;
    else if(p.Check_enemies(c)) found =  true;
    else found = false;
    if (!found) {c.setX(-1);c.setY(-1);}
    //c=start;
    return c;
}

//Imposta le coordinate di inizio sparo
void Shooter::Set_Coordinates(Coordinates c){
    this->c=c;
}

