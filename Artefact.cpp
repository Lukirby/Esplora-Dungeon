//created by Luca Panariello
#include "Artefact.hpp"

Artefact::Artefact(){};

Artefact::Artefact(char A, int score, Coordinates C){
    this->A=A;
    this->score=score;
    this->coor=C;
}

char Artefact::getType(){return A;}

int Artefact::getScore(){return score;}

Coordinates Artefact::getCoordinates(){return coor;}