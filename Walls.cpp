//created by Luca Panariello 

#include "Walls.hpp"
//ACS_HLINE - Lineatta Orizzontale definita in N_Curses
const char h='q';       
//ACS_VLINE - Lineatta Veriticale definita in N_Curses
const char v='x';
//ACS_PLUS - Croce '+' definita in N_Curses
const char p='n';       
//ACS_CKBOARD - Carattere Speciale simile a scacchiera definito in N_Curses
//Simboleggia il muro "speciale" l'idea è che sia di vetro
const char s='a';       


Walls::Walls(){}

Walls::Walls(bool E[], int sty, int stx, WINDOW* play, bool first){
    this->play=play;
    this->sty=sty;
    this->stx=stx;
    this->has_glass=false;
    
    //La prima stanza non ha muri
    if (first){
        for (int i=0; i<11; i++){W[i]=0;}                     
    } else {
    
        srand(time(0));
    
        //randomizzo i muri vicini all'entrate
        int r;
        for (int i=0; i<4; i++){
            if (E[i]) {W[i]=1;} 
            else {
                W[i]=rand()%2;
                if (W[i]==1) {W[i]=(rand()%2)+2;}
            }      
        }

        //Randomizzo (se possibile) muri che vanno dall'altro verso il basso
        if (!E[0] && !E[2]) {W[4]=(rand()%2)+1;} else {W[4]=0;}   

        //Randomizzo (se possibile) muri che vanno da sinista verso il destra
        if (!E[1] && !E[3]) {W[5]=(rand()%2)+1;} else {W[5]=0;}   

        //randomizzo i muri "angolari"
        if (W[3]<2 && W[0]<2) {W[6]=(rand()%3);} else {W[6]=0;}   
        if (W[0]<2 && W[1]<2) {W[7]=(rand()%3);} else {W[7]=0;}   
        if (W[1]<2 && W[2]<2) {W[8]=(rand()%3);} else {W[8]=0;}   
        if (W[2]<2 && W[3]<2) {W[9]=(rand()%3);} else {W[9]=0;}   
        
        //randomizzo il quadrato centrale
        if (W[4]==0 && W[5]==0) {W[10]=rand()%4;} else {W[10]=0;} 
        
        //Controllo se ci sono muri speciali
        if (W[10]==3 || W[4]==2 || W[5]==2) {this->has_glass=true;}
        else {
            for (int i=0;i<4 && !this->has_glass; i++){
            if (W[i]==3 || W[i+6]==2){this->has_glass=true;}}
        }
    }                                                         
}

void Walls::print_lines(int start, int end, int position, char c, bool direction){
    //stampo un muro a linee ne decido la direzione con un booleano
    if (direction){ // True = Orizziontale
        for (int i=start; i<end; i++) {mvwaddch(play,position,i,NCURSES_ACS(c));}
    } else {        // False = Verticale
        for (int i=start; i<end; i++) {mvwaddch(play,i,position,NCURSES_ACS(c));}
    }
}                                                             

void Walls::print_square(int ul, int ur, int dl, int dr,bool special, bool direction){
        if (special) {
        for (int i=ul; i<dl+1; i++){mvwaddch(play,i,ur,NCURSES_ACS(s));}
        for (int i=ul; i<dl+1; i++){mvwaddch(play,i,dr,NCURSES_ACS(s));}
        for (int i=ur+1; i<dr; i++){mvwaddch(play,ul,i,NCURSES_ACS(s));}
        for (int i=ur+1; i<dr; i++){mvwaddch(play,dl,i,NCURSES_ACS(s));}
        } else {
        for (int i=ul+1; i<dl; i++){mvwaddch(play,i,ur,NCURSES_ACS(v));}
        for (int i=ul+1; i<dl; i++){mvwaddch(play,i,dr,NCURSES_ACS(v));}
        for (int i=ur+1; i<dr; i++){if ((i==ur+6) && !direction) {} else mvwaddch(play,ul,i,NCURSES_ACS(h));}
        for (int i=ur+1; i<dr; i++){if ((i==ur+6) && direction) {} else mvwaddch(play,dl,i,NCURSES_ACS(h));}
        mvwaddch(play,ul,ur,NCURSES_ACS(p));
        mvwaddch(play,dl,ur,NCURSES_ACS(p));
        mvwaddch(play,dl,dr,NCURSES_ACS(p));
        mvwaddch(play,ul,dr,NCURSES_ACS(p));
        }
}                                                          

void Walls::print_central_square(int ul, int ur, int dl, int dr, bool holed, char c){
        char c1, c2;
        //scelgo il carattere da stampare speciale oppure no
        if (c==s){c1=s; c2=s;} else {c=v;c1=h; c2=p;} 
        //il quadrato può essere "bucato" oppure no
        if (!holed) {
        for (int i=ul; i<dl+1; i++){mvwaddch(play,i,ur,NCURSES_ACS(c));}
        for (int i=ul; i<dl+1; i++){mvwaddch(play,i,dr,NCURSES_ACS(c));}
        for (int i=ur+1; i<dr; i++){mvwaddch(play,ul,i,NCURSES_ACS(c1));}
        for (int i=ur+1; i<dr; i++){mvwaddch(play,dl,i,NCURSES_ACS(c1));}
        } else {
        for (int i=ul+1; i<dl; i++){if (i!=(sty-1)/2) mvwaddch(play,i,ur,NCURSES_ACS(v));}
        for (int i=ul+1; i<dl; i++){if (i!=(sty-1)/2) mvwaddch(play,i,dr,NCURSES_ACS(v));}
        for (int i=ur+1; i<dr; i++){if (i!=(stx-1)/2) mvwaddch(play,ul,i,NCURSES_ACS(h));}
        for (int i=ur+1; i<dr; i++){if (i!=(stx-1)/2) mvwaddch(play,dl,i,NCURSES_ACS(h));}
        }
        mvwaddch(play,ul,ur,NCURSES_ACS(c2));
        mvwaddch(play,dl,ur,NCURSES_ACS(c2));
        mvwaddch(play,dl,dr,NCURSES_ACS(c2));
        mvwaddch(play,ul,dr,NCURSES_ACS(c2));
}                                                        

void Walls::print(){
    //stampo tutti i muri che son già stati randomizzati con una serie di switch
    switch (W[0]){
        case 0:
        break;

        case 1:
            for (int i=-8; i<9; i++){if (i!=0) {mvwaddch(play,4,(stx-1)/2+i,NCURSES_ACS(h));}}
            for (int i=1; i<4; i++){mvwaddch(play,i,((stx-1)/2)-9,NCURSES_ACS(v));}
            for (int i=1; i<4; i++){mvwaddch(play,i,((stx-1)/2)+9,NCURSES_ACS(v));}    
            mvwaddch(play,4,((stx-1)/2)-9,NCURSES_ACS(p));
            mvwaddch(play,4,((stx-1)/2)+9,NCURSES_ACS(p));
        break;

        case 2:
            print_lines(1,stx-1,6,h,true);
        break;

        case 3:
            print_lines(1,stx-1,6,s,true);
        break;
        }
        
        switch (W[2]){
            case 0:
            break;
            case 1:
                for (int i=-9; i<10; i++){if (i!=0) {mvwaddch(play,sty-5,((stx-1)/2)+i,NCURSES_ACS(h));}}
                for (int i=1; i<4; i++){mvwaddch(play,sty-5+i,((stx-1)/2)+9,NCURSES_ACS(v));}
                for (int i=1; i<4; i++){mvwaddch(play,sty-5+i,((stx-1)/2)-9,NCURSES_ACS(v));}
                mvwaddch(play,sty-5,((stx-1)/2)+9,NCURSES_ACS(p));
                mvwaddch(play,sty-5,((stx-1)/2)-9,NCURSES_ACS(p));
            break;
            case 2:
                print_lines(1,stx-1,sty-6,h,true);
            break;
            case 3:
                print_lines(1,stx-1,sty-6,s,true); 
            break;
    }

    switch (W[1]){
        case 0:
        break;

        case 1:
            for (int i=-3; i<4; i++){if (i!=0) {mvwaddch(play,((sty-1)/2)+i,stx-9,NCURSES_ACS(v));}}
            for (int i=stx-8; i<stx-1; i++){mvwaddch(play,((sty-1)/2)-4,i,NCURSES_ACS(h));}
            for (int i=stx-8; i<stx-1; i++){mvwaddch(play,((sty-1)/2)+4,i,NCURSES_ACS(h));}
            mvwaddch(play,((sty-1)/2)-4,stx-9,NCURSES_ACS(p));
            mvwaddch(play,((sty-1)/2)+4,stx-9,NCURSES_ACS(p));
        break;
        
        case 2:
            print_lines(1,sty-1,stx-14,v,false);
        break;
        
        case 3:
            print_lines(1,sty-1,stx-14,s,false);
        break;
    }
        
    switch (W[3]){
        case 0:
        break;
        
        case 1:
            for (int i=-3; i<4; i++){if (i!=0) {mvwaddch(play,((sty-1)/2)+i,8,NCURSES_ACS(v));}}
            for (int i=1; i<8; i++){mvwaddch(play,((sty-1)/2)-4,i,NCURSES_ACS(h));}
            for (int i=1; i<8; i++){mvwaddch(play,((sty-1)/2)+4,i,NCURSES_ACS(h));}
            mvwaddch(play,((sty-1)/2)-4,8,NCURSES_ACS(p));
            mvwaddch(play,((sty-1)/2)+4,8,NCURSES_ACS(p));
        break;
        
        case 2:
            print_lines(1,sty-1,12,v,false);
        break;
        
        case 3:
            print_lines(1,sty-1,12,s,false);
        break;
    }

    switch (W[4]){
        case 0:
        break;
    
        case 1:
            for (int i=1;i<sty-1;i++){if (i!=(sty-1)/2) mvwaddch(play,i,(stx-1)/2,NCURSES_ACS(v));}
        break;
            
        case 2:
            for (int i=1;i<sty-1;i++){if (i==((sty-1)/2)+3 || i==((sty-1)/2)-2) {} else mvwaddch(play,i,(stx-1)/2,NCURSES_ACS(v));}
        break;
    }

    switch (W[5]){
        case 0:
        break;
        case 1:
            for (int i=1;i<stx-1;i++){if (i!=(stx-1)/2) mvwaddch(play,(sty-1)/2,i,NCURSES_ACS(h));}
        break;
        case 2:
            for (int i=1;i<stx-1;i++){if (i==((stx-1)/2)+6 || i==((stx-1)/2)-6) {} else mvwaddch(play,(sty-1)/2,i,NCURSES_ACS(h));}
        break;
    }
        
    switch (W[6]){
        case 0:
        break;

        case 1:
            print_square(2,2,6,((stx-1)/2)-11,false,true);
        break;

        case 2:
            print_square(2,2,6,((stx-1)/2)-11,true,true);
        break;
    }

    switch (W[7]){
        case 0:
        break;
        
        case 1:
            print_square(2,stx-15,6,stx-3,false,true);
        break;
        
        case 2:
            print_square(2,stx-15,6,stx-3,true,true);
        break;
    }
        
    switch (W[9]){
        case 0:
        break;
        
        case 1:
            print_square(((sty-1)/2)+6,2,sty-3,((stx-1)/2)-11,false,false);
        break;
        
        case 2:
            print_square(((sty-1)/2)+6,2,sty-3,((stx-1)/2)-11,true,false);
        break;
    }

    switch (W[8]){
        case 0:
        break;
        
        case 1:
            print_square(((sty-1)/2)+6,stx-15,sty-3,stx-3,false,false);
        break;
        
        case 2:
            print_square(((sty-1)/2)+6,stx-15,sty-3,stx-3,true,false);
        break;
    }
        
    switch (W[10]) {
        case 0:
        break;
        
        case 1:
            print_central_square(((sty-1)/2)-4,((stx-1)/2)-9,((sty-1)/2)+4,((stx-1)/2)+9,true,'L');
        break;
        
        case 2:
            print_central_square(((sty-1)/2)-4,((stx-1)/2)-9,((sty-1)/2)+4,((stx-1)/2)+9,false,'L');
        break;
        
        case 3:
            print_central_square(((sty-1)/2)-4,((stx-1)/2)-9,((sty-1)/2)+4,((stx-1)/2)+9,false,s);
        break;
    }
}           

int Walls::getWall(int i){
    return W[i];
}           

bool Walls::get_GlassInfo(){
    return this->has_glass;
}