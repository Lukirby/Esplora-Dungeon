//created by Federica Santisi
#include "EnemiesHandler.hpp"

EnemiesHandler::EnemiesHandler(){};

EnemiesHandler::EnemiesHandler(WINDOW *curwin, SpawnPoints S, int lvl, bool first_room){
    this -> curwin = curwin;
    this -> El = Elements(curwin);
    this -> S = S;
    this -> lvl = lvl;
    this -> first_enemy = true;
    if(first_room == true){
        n_enemies = 0;
    }else{
    int n = S.get_nEnemies();
    srand(time(0));
    this -> n_enemies = (rand()%n)+1;
    if(this -> n_enemies==1){this -> n_enemies++;}
    }
}

//Funzione che genera le probabilità random di generazione dei nemici
int EnemiesHandler::Random(){
    int random;
    int c;
    int t;
    if(first_enemy){
        t = rand()%3;
        switch(c){
        case 0:
            random = 0;
            first_enemy=false;
            break;
        case 1:
            random = 2;
            first_enemy=false;
            break;
        case 2:
            random = 4;
            first_enemy=false;
            break;
        default:
        break;
        }
    }else if(lvl<= 5){ 
        c = (rand()%30)+1; 
         if(c<=20){
            random=3;
        }
        else{
            random=1;
        }
       
    }else{
        c = (rand()%30)+1; //+1
        if(c<=5){
            random=1;
        }else if(c<=15){
            random=3;
        }else{
            random=5;
        }
    }
    return random;
}

//Questo metodo assegna ad ogni nemico le proprie specifiche
void EnemiesHandler::GenerateEnemiesType(){
    int random;
    for(int i=0 ; i<n_enemies; i++){
        random = Random();
        switch (random)
        {
        case 0:
            Type[i] = '#' ;
            Life_points[i] = 20; 
            Score[i] = 10;
            Damage[i] = 0;
            Shoot[i] = 0;
            Move[i] = 0;
            Armed[i] = false;
            break;
        case 1:
            Type[i] = '#';
            Life_points[i] = 20;
            Score[i] = 20;
            Damage[i] = 0;
            Shoot[i] = 0;
            Move[i] = (rand()%5)+1;
            Armed[i] = false;
            break;
        case 2:
            Type[i] = '%';
            Life_points[i] = 30;
            Score[i] = 40;
            Damage[i] = 10;
            Shoot[i] = 0;
            Move[i] = 0;
            Armed[i] = true;
            break;
        case 3:
            Type[i] = '%';
            Life_points[i] = 30;
            Score[i] = 30;
            Damage[i] = 10;
            Shoot[i] = 0;
            Move[i] = (rand()%5)+1;
            Armed[i] = true;
            break;
        case 4:
            Type[i] = '&';
            Life_points[i] = 40;
            Score[i] = 40;
            Damage[i] = 5;
            Shoot[i] = (rand()%2)+1;
            Move[i] = 0;
            Armed[i] = false;
            break;
        case 5:
            Type[i] = '&';
            Life_points[i] = 40;
            Score[i] = 50;
            Damage[i] = 5;
            Shoot[i] = (rand()%2)+1;
            Move[i] = (rand()%5)+1;
            Armed[i] = false;
            break; 
        default:
            break;
        }
    }
}

//Genera le coordinate dei nemici in 
void EnemiesHandler::GenerateEnemiesCord(){
    Coordinates cords = Coordinates(10,10); 
    int random;
    for(int i=0; i<n_enemies; i++){
        if(Move[i]==0) cords = S.extract(0);
        else cords = S.extract(1);
        Enemy E = Enemy(curwin, cords, Type[i], Life_points[i], Damage[i], Score[i], lvl, false, Move[i], Shoot[i], false, Armed[i]);
        El.Insert_enemy(E);
    }
    
}

//Elimina il nemico dalla lista e decrementa il contatore di nemici
int EnemiesHandler::RemoveEnemy(int dam, Coordinates C){
    int score=this -> El.Delete_enemy(dam,C);
    if (score!=0) this -> n_enemies--;
    return score;
}

//Stampa del nemico nella stanza
void EnemiesHandler::PrintEnemy(){
    if(n_enemies>0) {
        this -> El.PrintEnemies();         
    }
    
}

//Set del nemico
void EnemiesHandler::Build(){
    if(n_enemies!=0){
        GenerateEnemiesType();
        GenerateEnemiesCord();
    }
}

//Imposta il tipo di azione del nemico (spara, si muove, attacca, ecc...)
int EnemiesHandler::EnemyChoise(Coordinates PlayerC){
    return El.EnemyChoise(PlayerC);
}
