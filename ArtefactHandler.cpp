//created by Luca Panariello
#include "ArtefactHandler.hpp"

ArtefactHandler::ArtefactHandler(){}

ArtefactHandler::ArtefactHandler(WINDOW* curwin,bool glass_info, bool has_door, bool from_door, SpawnPoints S, bool first_room){
    this->El=Elements(curwin);
    this->curwin=curwin;
    this->glass_info=glass_info;
    this->glass_info2=glass_info;
    this->has_door=has_door;
    this->from_door=from_door;
    this->S=S;
    if (first_room){this->n_artefacts=0;}else{
    srand(time(0));
    int n=S.get_nArtefact();
    this->n_artefacts=(rand()%n)+1;
    }
}

int ArtefactHandler::RandomType(){
    int random;
    int c=rand()%100;
    //Stampo l'Artefatto 'A' se sono appena entrato da una porta
    if (c<10 || from_door){
        random=6; if (from_door){from_door=false;}
    } else if (c<37) {random=3;} else
    if (c<62) {if (c<50) {random=4;} else {random=5;}} else
    if (c<88) {if (c<75) {random=0;} else {random=1;}} else {random=2;}
    return random;
}

void ArtefactHandler::GenerateArtefactType(){
    for (int i=0; i<n_artefacts; i++){
        {
            int random;
            random=RandomType();
            switch (random){
            case 0:
                Type[i]='H';
                Score[i]=10;
                break;
            case 1:
                Type[i]='K';
                Score[i]=10;
                break;
            case 2:
                Type[i]='S';
                Score[i]=30;
                break;
            case 3:
                Type[i]='B';
                Score[i]=20;
                break;
            case 4:
                Type[i]='G';
                Score[i]=50;
                break;
            case 5:
                Type[i]='C';
                Score[i]=20;
                break;
            case 6:
                Type[i]='A';
                Score[i]=40;
            }

        }
    }
}

void ArtefactHandler::GenerateArtCord(){
    Coordinates cord=Coordinates(10,10); int random;
    //Attenzione a mettere artefatti essenziali come chiavi e mantelli nei muri speciali
    for (int i=0;i<n_artefacts;i++){
        if (Type[i]=='C'){
            //stampo il mantello fuori dai muri speciali
            cord=S.extract(2);
        } else {
            //stampo il primo artefatto fuori dai muri speciali
            if(i==0){random=2;} else {random=(rand()%2)+2;}
            cord=S.extract(random);
        }
        //creo l'artefatto e lo inserisco nella lista_artefatti in Elements
        Artefact A=Artefact(Type[i],Score[i],cord);
        El.Insert_artefact(A);
    }
}

void ArtefactHandler::build(){
    if (n_artefacts!=0){
    GenerateArtefactType();
    GenerateArtCord();
    }
}

Artefact ArtefactHandler::RemoveArtefact(char A, Coordinates C){
    this->n_artefacts--;
    return this->El.Delete_artefact(A,C);
}

void ArtefactHandler::PrintArtefact(){
    if (n_artefacts>0) {this->El.PrintArtefact();}
}