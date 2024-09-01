#include <conio.h>
#include "list.h"
#include<cstdlib>
#include <unistd.h>
#include "invaders.h"
#include "map.h"


const int MAX_X_MAP = 20;
const int MAX_Y_MAP = 100;
t_list* enemies;

void level1();

int main(){
    system("cls");

    enemies = new_list();

    char** map = create_map(MAX_X_MAP, MAX_Y_MAP);

    initialize_map(map, MAX_X_MAP, MAX_Y_MAP);

    print_map(map, MAX_X_MAP, MAX_Y_MAP);

    level1();

    return 0;
}

void level1(){
    for(int i = 0; i < 3; i++){
        invader invasor(1+space_inbetween_invader*i,1);
        list_add_element(&invasor,enemies);
    }

    draw_invaders(enemies);

    getch();
    
    /*

    while(1){
        for(int i = 0; i < 40; i++){
            invador.move(i,0);
            invador1.move(i,0);
            invador2.move(i,0);
            invador3.move(i,0);
            invador4.move(i,0);
            invador5.move(i,0);
            usleep(100000);
        }
        
        invador.move(0,1);
        invador1.move(0,1);
        invador2.move(0,1);
        invador3.move(0,1);
        invador4.move(0,1);
        invador5.move(0,1);

        for(int i = 0; i > -40; i--){
            invador.move(i,0);
            invador1.move(i,0);
            invador2.move(i,0);
            invador3.move(i,0);
            invador4.move(i,0);
            invador5.move(i,0);
            usleep(100000);
        }

        invador.move(0,1);
        invador1.move(0,1);
        invador2.move(0,1);
        invador3.move(0,1);
        invador4.move(0,1);
        invador5.move(0,1);
    }*/
}