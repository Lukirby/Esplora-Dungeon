//created by Giulia Torsani
#include "Menubar.hpp"

Menubar::Menubar(){
	this->Choice=Choice;
	this->hasgame=false;
	this->sog=true;
    //prende la dimensione dello schermo
    getmaxyx(stdscr, this->yMax, this->xMax);
	this->max=Coordinates(50,26);
   	this->cursor = Coordinates (25,13);
	//CREATE A WINDOW FOR OUR INPUT
	this->menuwin = newwin(12, xMax-12, yMax-25, 5);
	keypad(menuwin, true);
}

void Menubar::GenerateMenu(){
	//CREATE A WINDOW FOR OUR INPUT
	this->menuwin = newwin(12, xMax-12, yMax-25, 5);
	keypad(menuwin, true);
    box(menuwin, 0, 0);
    refresh;
    wrefresh(menuwin);
}

void Menubar::ShowMenu(){

box(menuwin, 0, 0);
refresh;
wrefresh(menuwin);

string status[3]={" ","Pause","GameOver"};

string choices[3] = {"New Game", "Keep playing", "Quit"};
int choice;
int highlight = 0;

	while(1){

	for(int i=0; i<3; i++){
	if(i==highlight)
	wattron(menuwin, A_REVERSE);
	mvwprintw(menuwin, i+1, 1, choices[i].c_str());
	wattroff(menuwin, A_REVERSE);
	 box(menuwin, 0, 0); // boxing che evita la sparizione dei bordi se si restringe il terminale 
	}

	if (!hasgame && sog){
	mvwprintw(menuwin, 5, 13, status[0].c_str());
	} else if(sog){
	mvwprintw(menuwin, 5, 13, status[1].c_str());
	}else{
	mvwprintw(menuwin, 5, 13, status[2].c_str());
	}
	box(menuwin, 0, 0);
	
	choice = wgetch(menuwin);

	switch(choice){
	case KEY_UP:
	highlight--;
	if(highlight == -1)
	highlight=0;
	break;
	case KEY_DOWN:
	highlight++;
	if(highlight == 3)
	highlight=2;
	break;
	default:
	break;
	}
	if(choice == 10)
	break;
	 box(menuwin, 0, 0);// boxing che evita la sparizione dei bordi se si restringe il terminale 
    }

	this->Choice=highlight;
	this->b=true;
};

void Menubar::PlayMenu(){
while(b){
	ShowMenu();
	werase(menuwin);
	wrefresh(menuwin);
	//controllo la scelta
	switch(Choice){
	case 0:
	//"New Game" inizializza la stanza e i nemici per la nuova partita
	if (hasgame==true) {MH.~MapHandler();} //Distruttore
	else {hasgame=true;} //Gioco in Corso
		MH=MapHandler(xMax,yMax,max,cursor,'@',NULL);
		MH.PlayGame();
		this->sog=!MH.PlayerDeath();
		if (!this->sog){this->hasgame=false;}
	break;
	case 1:
		//"Keep playing" si toglie la pausa
		if(hasgame==true){
			MH.PlayGame();
			this->sog=!MH.PlayerDeath();
			if (!this->sog){this->hasgame=false;}
		}
	break;
	case 2:
		//"Quit" esce dal gioco
		b=false;
		MH.CloseGame();
		MH.~MapHandler();
	break;
	default:
	break;
	}
}
		werase(menuwin);
		wrefresh(menuwin);
};
