//created by Luca Panariello
#include "Enemies2.hpp"
using namespace std;

class Artefact{
    protected:
    //Tipo di Artefatto
    // H - Hearts : Aggiungono vita al giocatore
    // K - Keys   : Aumenta il contatore chave del giocatore e permette di aprire porte
    // S - Shield : Rende il Giocatore invincibile per un colpo
    // B - Bullets: Munizioni dell'Arma
    // C - Cloak  : Permette di attraversare muri speciali
    // G - Gold   : Ottieni Punteggio Extra
    // A - Artefatto : Aumenta Pernementemente la vita del Giocatore
    char A;
    
    //Punteggio conseguito per aver raccolto l'artefatto
    int score;
    
    //Posizione dell'artefatto nella stanza
    Coordinates coor;

    public:
    //Costruttore Predefinito - Inutilizzato
    Artefact();

    //Costruttore
    Artefact(char A, int score, Coordinates C);
    
    //Ritorna il Tipo di Artefatto
    char getType();
    
    //Ritorna il Punteggio dell'Artefatto
    int getScore();

    //Ritorna le Coordinate dell'Artefatto
    Coordinates getCoordinates();
};