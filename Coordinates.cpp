//created by Giulia Torsani
#include "Coordinates.hpp"

Coordinates::Coordinates(int posX, int posY) {
    x = posX;
    y = posY;
}

void Coordinates::increaseX(int inc) {
    x = x + inc;
}

void Coordinates::decreaseX(int dec) {
    x = x - dec;
}

void Coordinates::increaseY(int inc) {
    y = y + inc;
}

void Coordinates::decreaseY(int dec) {
    y = y - dec;
}

void Coordinates::setX(int newX) {
    x = newX;
}

void Coordinates::setY(int newY) {
    y = newY;
}

int Coordinates::getX() {
    return x;
}

int Coordinates::getY() {
    return y;
}

bool Coordinates::sameCoordinates(Coordinates coords) {
    if ((x == coords.getX()) && (y == coords.getY()))
    	return true;
    else
    	return false;
}