//created by Giulia Torsani


#include "Entity.hpp"

    Entity::Entity(WINDOW* win,Coordinates coords, char c,int pv, int damage, int score, int lvl, bool isdead){
        this->coordinates=coords;
        this->character=c;
        this->pv=pv;
        this->damage=damage;
        this->score=score;
        this->lvl=lvl;
        this->isdead=isdead;
        this->curwin=win;
        this->S=Shooter(win,coords);
        this->maxLife=this->pv;

    }
  
   void Entity::setCoordinates(Coordinates coords) {
    this->coordinates = coords;
    };

    Coordinates Entity::getCoordinates() {
    return coordinates;
    };

    void Entity::setpv(int pv){
         this->pv=pv; 
    };

    int Entity::getpv(){
        return pv;
    };

    int Entity::getMaxLife(){
        return maxLife;
    };

    void Entity::editpv(int points){ 
        if(getpv()+points<=maxLife){
            pv=pv+points;
        }else {
            pv=maxLife;
             }
        if(pv<=0){
            pv=0;
            isdead=true;
        }
    };

    void Entity::setdamage(int damage){
        this->damage=damage;
    };

    int Entity::getdamage(){
        return damage;
    };

    void Entity::setscore(int score){
        this->score=score;
    };

    int Entity::getscore(){
        return score;
    };

    void Entity::setLevel(int lvl){
        this->lvl=lvl;
    };

    int Entity::getLevel(){
        return lvl;
    };

    void Entity::setchar(char c){
        this->character=c;
    };

   char Entity::getchar(){
        return character;
    }

    bool Entity::getisdead(){
        return isdead;
    };

    void Entity::checkisdead(){
        if(pv<=0)
        isdead=true;
    };

    void Entity::mvup(){
        mvwaddch(curwin, coordinates.getY(), coordinates.getX(), ' ');
        coordinates.decreaseY(1);
    }

    void Entity::mvdown(){
        mvwaddch(curwin, coordinates.getY(), coordinates.getX(), ' ');
        coordinates.increaseY(1);
    }

    void Entity::mvleft(){
        mvwaddch(curwin, coordinates.getY(), coordinates.getX(), ' ');
        coordinates.decreaseX(1);
        
    }
    void Entity::mvright(){
        mvwaddch(curwin, coordinates.getY(), coordinates.getX(), ' ');
        coordinates.increaseX(1);
    
    }
    void Entity::getmv(int choice){
        switch(choice){
            case 0:
                mvup();
                break;
            case 1:
                mvright();
                break;
            case 2:
                mvdown();
                break;
            case 3:
                mvleft();
                break;
            default:
            break;
        }
    }

    void Entity::display(){
        mvwaddch(curwin, coordinates.getY(), coordinates.getX(), character);
    }

    Shooter Entity::useShoot(){
    return this->S;
    }

    void Entity::setShoot(){
    this->S.Set_Coordinates(this->coordinates);
    }