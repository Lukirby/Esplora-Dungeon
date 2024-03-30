//created by Luca Panariello
#include "SpawnPoints.hpp"

class ArtefactHandler{

    protected:

    //Struttura Dati Contentente gli Artefatti
    Elements El;

    //Finestra di Stampa e Gestione degli Artefatti
    WINDOW* curwin;

    //Numero di Artefatti Gestiti (in una singola stanza)
    int n_artefacts;

    //Primo Booleano che Indica se vi sono muri speciali
    bool glass_info;
    //Secondo Booleano che Indica se vi sono muri speciali
    bool glass_info2;
    //Booleano che Indica se vi è una Porta
    bool has_door;

    bool from_door;

    //Array Dinamico (gestito da n_artefact) che contiene il possibile Tipo di Artefatto
    char Type[10];
    //Array Dinamico (gestito da n_artefact) che contiene il possibile Score di Artefatto
    int Score[10];

    //Struttura Dati con Possibili Coordinate per gli Artefatti
    SpawnPoints S;

    //Sceglie Randomicamente il tipo di Artefatto
    int RandomType();

    //Imposta I tipi di Artefatto
    void GenerateArtefactType();

    //genera coordinate per stampare artefatti in ogni stanza
    void GenerateArtCord(); 

    public:
    //Costruttore Predefinito - Inutilizzato
    ArtefactHandler();
    //Costruttore
    ArtefactHandler(WINDOW* curwin, bool glass_info, bool has_door, bool from_door, SpawnPoints S, bool first_room);

    //Rimuove l'artefatto una volta raccolto
    Artefact RemoveArtefact(char A, Coordinates C);

    //Stampa gli Artefatti
    void PrintArtefact();

    //Genera gli artefatti inserendoli nella Classe Elements
    //e gli assegna tipo e coordinate
    void build();
};