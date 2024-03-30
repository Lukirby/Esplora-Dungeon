//created by Giulia Torsani 
#include "Map.hpp"

class Gamestate{

protected:
    WINDOW* gamestate;

public:
    Gamestate();

    //Mostra il GameState
    void ShowState(Player p); // stampa lo stato del giocatore durante la partita

};