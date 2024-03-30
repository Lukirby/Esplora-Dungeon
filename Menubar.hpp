//created by Giulia Torsani
#include "MapHandler.hpp"

class Menubar{

protected:
    WINDOW* menuwin;
    int Choice;
    int xMax;
    int yMax;
    Coordinates max;
    Coordinates cursor;
    bool sog; //state of game, true se ancora vivo, else morto (serve per far comparire "Pause" o "Game over")
    bool b; //booleano per utilizzo menu
    bool hasgame; //true se ho una partita in corso
    MapHandler MH; //Controllo Mappa - Gioco Principale

public:
    Menubar();

    void GenerateMenu();

    void ShowMenu(); // stampa il menu bar

    void PlayMenu(); // visualizza la scelta fatta

};