//created by Federica Santisi
#include "Elements2.hpp"


Elements::Elements(){}

Elements::Elements(WINDOW* curwin){
    this -> he = NULL;
    this -> ha = NULL;
    this -> curwin = curwin;
}

//Ricerca del nemico all'interno della lista
bool Elements::Search_enemy(char e){        
    bool found = false;
    if(he == NULL){
        return he; 
    }else{
        while(he!=NULL && !found){
            if(he -> e.getchar() == e){
                found = true;
            }
        }
        return found;
    }
}

//Ricerca dell'artefatto all'interno della lista
bool Elements::Search_artefacts(char a){    
    bool found = false;
    if(ha == NULL){
        return ha;
    }else{
        while(ha!=NULL && !found){
        if(ha -> a.getType() == a){
            found = true;
            }
        }
        return found;
    }
}

//Inserimento del nemico nella lista
void Elements::Insert_enemy(Enemy E){
    if(he==NULL){
        he = new enemies;
        he -> e = E;
        he -> next = NULL;
    }else{
        p_enemies tmp;
        tmp = new enemies;
        tmp -> e = E;
        tmp -> next = he;
        he = tmp;
    }
}

//Inserimento dell'artefatto nella lista
void Elements::Insert_artefact(Artefact A){
    if(ha==NULL){
        ha = new artefacts;
        ha-> a = A;
        ha -> next = NULL;
    }else{
        p_artefacts tmp;
        tmp = new artefacts;
        tmp -> a = A;
        tmp -> next = ha;
        ha = tmp;
    }
}

//Elimina nemico dalla lista
int Elements::Delete_enemy(int dam, Coordinates C){
    if(he==NULL){
        exit(15); //Errore Caso Impossibile
    }else{
        p_enemies head = he;
        p_enemies prec = he;
        p_enemies succ = he -> next;
        Enemy F;
        if (he->e.getCoordinates().sameCoordinates(C)){//nel caso in cui le coordinate del nemico
            he->e.editpv(-dam);                        //e del player coincidono, cancello
            if(he->e.getisdead()){
            F=he->e;
            he = he -> next;
            delete head;
            head=NULL;
            return F.getscore();
            }
        }else{
            head=head->next;
            succ=succ->next;
            while(head!=NULL){
                if (head->e.getCoordinates().sameCoordinates(C)){
                    head->e.editpv(-dam);
                    if(head->e.getisdead()){
                    prec -> next = succ;
                    F=head->e;
                    delete head;
                    head=NULL;
                    return F.getscore();
                    }
                }else{
                    prec = prec -> next;
                    head = head -> next;
                    if (succ!=NULL) succ = succ -> next;
                }
            }
        }
        return 0;
    }
}


//Rimuovi artefatto dalla lista
Artefact Elements::Delete_artefact(char A, Coordinates C){
    if(ha==NULL){
        exit(15); //Errore Caso Impossibile
    }else{
        p_artefacts head = ha;
        p_artefacts prec = ha;
        p_artefacts succ = ha -> next;
        Artefact D;
        if(ha-> a.getType()==A && ha->a.getCoordinates().sameCoordinates(C)){//Se il PLayer passa sopra
            D=ha->a;                                                         //l'artefatto per raccoglierlo, cancello
            ha = ha -> next;
            delete head;
            head=NULL;
        }else{
            head=head->next;
            succ=succ->next;
            while(head!=NULL){
                if(head->a.getType()==A && head->a.getCoordinates().sameCoordinates(C)){
                    prec -> next = succ;
                    D=head->a;
                    delete head;
                    head=NULL;
                }else{
                    prec = prec -> next;
                    head = head -> next;
                    if (succ!=NULL) succ = succ -> next;
                }
            }
        }
        return D;
    }
}

//Stampa dei nemici
void Elements::PrintEnemies(){
    p_enemies E = he;
    while(E!=NULL){
        mvwaddch(curwin,E->e.getCoordinates().getY(),E->e.getCoordinates().getX(),E->e.getchar());
        E=E->next;
    }
}

//Stampa degli artefatti
void Elements::PrintArtefact(){
    p_artefacts A=ha;
    while(A!=NULL){
        mvwaddch(curwin,A->a.getCoordinates().getY(),A->a.getCoordinates().getX(),A->a.getType());
        A=A->next;
    }
}

//Funzione che indica cosa deve fare il nemico (attaccare o muoversi)
int Elements::EnemyChoise(Coordinates PlayerC){
    p_enemies head=he; Enemy E; int damage = 0; int check_damage;
    while(head!=NULL){
        if (head->e.Is_move()==0){
            if (head->e.Is_armed()) damage=damage+head->e.Armed(PlayerC);
            else damage = damage + head->e.Shooting(PlayerC);
        }else 
        if (head->e.Is_shooting() == 0){
            check_damage=head->e.Armed(PlayerC); 
            if (check_damage==0) head->e.Moving(PlayerC);
            else damage = damage + check_damage;
        }else{
            check_damage = head->e.Shooting(PlayerC);
            if (check_damage == 0) head->e.Moving(PlayerC);
            else damage = damage + check_damage;
        }
        head=head->next;
    }
    return damage;
}