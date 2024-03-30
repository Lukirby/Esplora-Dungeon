//created by Giulia Torsani 
#include "Gamestate.hpp"

Gamestate::Gamestate(){
	//GET SCREEN SIZE
	int ymax, xmax;
	getmaxyx(stdscr, ymax, xmax);

	//CREATE A WINDOW FOR OUR INPUT
	this->gamestate = newwin(8, 50,0,(xmax/2)-25);

};

void Gamestate::ShowState(Player p){
	werase(gamestate);
    string score = to_string(p.getscore());
    string pv = to_string(p.getpv());
    string lvl = to_string(p.getLevel());
    string keys=to_string(p.getKeys());
	string bullets=to_string(p.getBullets());
	string zero=to_string(0);
	if (p.getBullets()<10){bullets = zero + bullets;}
	if(p.getKeys()<10){ keys = zero + keys;};
	if(p.getpv()<10){ pv = zero + pv;};
	string shield;
	string coat;
	string MaxLife=to_string(p.getMaxLife());

	if(p.hasShield()==true){
		shield="T";
	}else{
		shield="F";
	}

	if(p.hasCoat()==true){
		coat="T";
	}else{
		coat="F";
	}

	box(gamestate, 0, 0);
	mvwprintw(gamestate, 1, 1, "Score :");
	mvwprintw(gamestate, 1, 10, score.c_str());
	mvwprintw(gamestate, 3, 1, "pv:");
	mvwprintw(gamestate, 3, 10, pv.c_str());
	mvwprintw(gamestate, 3, 13, "/");
	mvwprintw(gamestate, 3, 14, MaxLife.c_str());
	mvwprintw(gamestate, 5, 1, "level:");
	mvwprintw(gamestate, 5, 10, lvl.c_str());
	mvwprintw(gamestate, 1, 19, "keys:");
	mvwprintw(gamestate, 1, 25, keys.c_str());
	mvwprintw(gamestate, 3, 19, "Shield:");
	mvwprintw(gamestate, 3, 27, shield.c_str());
	mvwprintw(gamestate, 5, 19, "Coat:");
	mvwprintw(gamestate, 5, 25, coat.c_str());
	mvwprintw(gamestate, 1, 32, "Bullets:");
	mvwprintw(gamestate, 1, 42, bullets.c_str());
	wrefresh(gamestate);
}
