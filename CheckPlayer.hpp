//created by Luca Panariello
#include "Interaction.hpp"

class CheckPlayer{
    protected:
        //Serve utilizzare i diversi metodi di controllo
        Interaction I;
    public:
        //Costruttore
        CheckPlayer(WINDOW* win=NULL);
        //Controlla che il giocatore sia in linea d'aria con il nemico
        //e che non ci sia nessun ostacolo di mezzo
        //in caso positivo ritorna un int che indica la direzione in cui attaccare
        int Check_Player_In_Sight(Coordinates EnemyC, Coordinates PlayerC);
        //Controlla che il giocatore si attaccato al nemico così che 
        //quest'ultimo possa attaccarlo ravvicinatamente
        bool Check_Player_next_to_Enemy(Coordinates EnemyC, Coordinates PlayerC);
};