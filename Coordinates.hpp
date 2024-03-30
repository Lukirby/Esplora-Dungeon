//created by Giulia Torsani
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ncurses.h>
#include <curses.h>

class Coordinates {

protected:
  //Coordinata X
  int x;
  //Coordinata Y
  int y;

public:
  //Costruttore
  Coordinates(int posX=0, int posY=0);

  //Aumenta la X del valore in input 
  void increaseX(int inc = 1);

  //Decrementa la X del valore in input
  void decreaseX(int dec = 1);

  //Aumenta la Y del valore in input
  void increaseY(int inc = 1);

  //Decrementa la Y del valore in input
  void decreaseY(int dec = 1);

  //Imposta la X con un nuovo valore in input
  void setX(int newX = 0);

  //Imposta la Y con un nuovo valore in input
  void setY(int newY = 0);

  //Ritorna la Coordinata X
  int getX();

  //Ritorna la Coordinata Y
  int getY();

  //Ritorna se le Coordinate solo uguali a quelle in input
  bool sameCoordinates(Coordinates coords);

};