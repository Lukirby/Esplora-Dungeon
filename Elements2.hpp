//created by Federica Santisi

/* La classe Elements 2 gestisce i nemici e gli artefatti  tramite una lista che contiene 
tutti gli elementi che verrano poi inseriti all'interno della stanza. In particolare
prevede l'implementazione di operazioni di ricerca, inserimento, rimozione, stampa
*/
#include "Artefact.hpp"

struct enemies{
    Enemy e;
    Movements M;
    enemies *next;
};

struct artefacts{
    Artefact a;
    artefacts *next;
};

typedef enemies *p_enemies;
typedef artefacts *p_artefacts;

class Elements{
protected:
    WINDOW* curwin; //Finestra di Stampa
    p_enemies he;
    p_artefacts ha;
public:
    Elements();     //Costruttore predefinito
    Elements(WINDOW* curwin);

    bool Search_enemy(char e);
    bool Search_artefacts(char a);

    void Insert_enemy(Enemy E);
    void Insert_artefact(Artefact A);

    int Delete_enemy(int dam, Coordinates C);
    Artefact Delete_artefact(char A, Coordinates C);

    void PrintArtefact();
    void PrintEnemies();

    int EnemyChoise(Coordinates PlayerC);
    
};