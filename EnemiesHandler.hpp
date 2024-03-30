//created by Federica Santisi

/*La classe EnemiesHandler gestisce le probabilità di generazione dei nemici e implementa
un metodo in cui ad ogni nemico vengono associate le proprie specifiche
*/
#include "ArtefactHandler.hpp"

class EnemiesHandler{
protected:
    WINDOW* curwin;
    Elements El;
    SpawnPoints S;
    char Type[6];
    int Life_points[6];
    int Score[6];
    int Damage[6];
    int Shoot[6];
    int Move[6];
    bool Armed[6];
    bool first_room;
    int lvl;
    int n_enemies;
    bool first_enemy;
public:
    EnemiesHandler();
    EnemiesHandler(WINDOW *curwin, SpawnPoints S, int lvl, bool first_room);

    int Random();

    void GenerateEnemiesType();
    void GenerateEnemiesCord();

    int RemoveEnemy(int dam, Coordinates C);
    void PrintEnemy();
    void Build();

    int EnemyChoise(Coordinates PlayerC);

};

/*
case 0: static enemy
char = #;
punti vita : 20;
punteggio : 10;
danno: 15;

case 1: movement enemy
char = #;
punti vita : 20;
punteggio : 20;
danno: 15;

case 2: static armed enemy
char = %;
punti vita : 30;
punteggio : 40;
danno: 10;

case 3: movement armed enemy
char = %;
punti vita : 30;
punteggio : 30;
danno: 10;

case 4: static shooter enemy
char = &;
punti vita : 40;
punteggio : 40;
danno: 5;

case 5: movement shooter enemy
char = &;
punti vita : 40;
punteggio : 50;
danno: 5;
*/
