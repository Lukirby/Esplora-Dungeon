//created by Luca Panariello
#include "Map.hpp"
Map::Map(){}

//costruttore
Map::Map(int sx, int sy){
    this->start=Coordinates(sx,sy);
    this->length=Coordinates(50,26);
    srand(time(0));
    int entrance=rand()%4;
    
    //creo lo schermo dove verranno stampate le stanze e gli elementi in essa
    this->screen=newwin(length.getY(),length.getX(),start.getY(),start.getX());
    keypad(this->screen,true);
    
    //creo la stanza iniziale
    Room room=Room(length.getY(),length.getX(),entrance,screen,false,true);
    
    //imposto i vari spawnpoint (generati in base alla stanza in input)
    SpawnPoints S=SpawnPoints();
    S.build(room,true);
    
    //genero gli artefatti di quella stanza
    ArtefactHandler ah=ArtefactHandler(screen,false,false,false,S,true);
    ah.build();

    //genero i nemici di quella stanza
    EnemiesHandler eh=EnemiesHandler(screen,S,0,true);
    eh.Build();

    //insersco nella struttura dati ad albero
    this->TR=TreeRoom(room,ah,eh);
    
    reload();
}

void Map::generate_room(int direction,int lvl){
    //controllo che la direzione verso cui siamo usciti corrisponde alla direzione di una porta;
    bool from_door = direction==TR.current_room().get_Doors().getWhereIsDoor();
    Room NR=Room(length.getY(),length.getX(),TR.opposite(direction),screen,from_door,false);
    SpawnPoints S=SpawnPoints(); S.build(NR,false);
    ArtefactHandler AH=ArtefactHandler(screen,NR.getWalls().get_GlassInfo(),NR.get_Doors().getHasDoor(),from_door,S,false);
    AH.build();
    EnemiesHandler EH=EnemiesHandler(screen,S,lvl,false);
    EH.Build();
    TR.insert(NR,direction,AH,EH);
    reload();
}

void Map::change_room(int x){
    clean_screen();
    TR.move(x);
    reload();
}

bool Map::explore(int x, int lvl){
    if (TR.get_tree_direction(x)==NULL) {generate_room(x,lvl); return true;} else {change_room(x); return false;}
}

void Map::clean_screen(){
    werase(screen);
}

WINDOW* Map::get_screen(){
    return this->screen;
}

Room Map::getRoom(){
    return TR.current_room();
}

ArtefactHandler Map::getArtefactHandler(){
    return TR.getAH();
}

EnemiesHandler Map::getEnemiesHandler(){
    return TR.getEH();
}

void Map::reload(){
    clean_screen();
    TR.getAH().PrintArtefact();
    TR.showEnemies();
    TR.current_room().print_room();
    wrefresh(screen);
}

Artefact Map::RemoveArtefact(char A, Coordinates C){
    return this->TR.RemoveArtefact(A,C);
}

int Map::RemoveEnemy(int damage, Coordinates C){
    return this->TR.RemoveEnemy(damage,C);
}

int Map::EnemyPhase(Coordinates PlayerC){
    return this->TR.EnemyPhase(PlayerC);
}

void Map::unlock(){
    this->TR.unlock();
}

int Map::opposite(int n){
    return TR.opposite(n);
}