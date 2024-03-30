//created by Luca Panariello 
#include "Room.hpp"

//Lista di Coordinate
struct list_of_coordinates{
    Coordinates C;
    list_of_coordinates* next;
};

//Definizione di p_lista come puntatore a lista di coordinate
typedef list_of_coordinates* p_list;

class LoC{
    protected:
    //Testa della Lista
    p_list L;          

    //Lunghezza della Lista
    int length;                     

    //Booleano che indica se la lista è Vuota
    bool empty;                     
    
    public:
    //Costruttore
    LoC();                          

    //Inserisci le Coordinate in Testa alla Lista
    void insert_c(Coordinates N);   

    //Cancella le Cordinate in un certo punto (n) della Lista
    Coordinates delete_c(int n);    

    //Ritorna se la Lista è vuota o meno
    bool is_empty();                

    //Ritorna la Lunghezza della Lista
    int get_length();
};