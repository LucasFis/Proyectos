#include <conio.h>
#include "list.h"
#include<cstdlib>
#include <unistd.h>
#include "invaders.h"
#include "map.h"


const int MAX_X_MAP = 20;
const int MAX_Y_MAP = 90;
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
    for(int i = 0; i < 8; i++){
        invader* invasor = new invader(1+space_inbetween_invader*i,1);
        list_add_element(invasor, enemies);
    }

    draw_invaders(enemies);

    move_invaders(enemies, 2, 0);
    move_invaders(enemies, 2, 0);
    move_invaders(enemies, 2, 0);
    move_invaders(enemies, -2, 0);
    move_invaders(enemies, -2, 0);
    move_invaders(enemies, -2, 0);

    getch();
}