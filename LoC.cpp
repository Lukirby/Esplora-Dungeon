//created by Luca Panariello 
#include "LoC.hpp"

LoC::LoC(){
    this->L=NULL;
    this->length=0;
    this->empty=true;
}

void LoC::insert_c(Coordinates N){
    if (this->empty) {
        this->L=new list_of_coordinates;
        this->L->C=N;
        this->L->next=NULL;
        this->length++;
        this->empty=false;
    } else {
        p_list newL = new list_of_coordinates;
        newL->C=N;
        newL->next=this->L;
        this->L=newL;
        this->length++;
    }
}

Coordinates LoC::delete_c(int n){
    //Rimozione tra Nodi
    Coordinates N;
    if (!this->empty && n<=this->length && n>0){    //Sempre Verificata
        p_list DEL; p_list PREC=NULL;
        DEL=this->L;
        while (n>1){
            PREC=DEL;
            DEL=DEL->next;
            n--;
        }
        N=DEL->C;
        if (PREC==NULL){this->L=DEL->next;} else {PREC->next=DEL->next;}
        delete DEL;
        this->length--;
        if (this->L==NULL) {this->empty=true;}
    }
    return N;
}

bool LoC::is_empty(){
    return this->empty;
}

int LoC::get_length(){
    return this->length;
}