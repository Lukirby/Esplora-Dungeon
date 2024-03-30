//created by Luca Panariello
#include "Menubar.hpp"

//Main del Progetto
int main () {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    Menubar MB=Menubar();
    MB.PlayMenu();
    MB.~Menubar();
    endwin();
    return 0;
}
