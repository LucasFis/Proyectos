#include <conio.h>
#include "list.h"
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include "invaders.h"
#include "map.h"
#include "shields.h"
#include "ship.h"

const int MAX_X_MAP = 20;
const int MAX_Y_MAP = 80;
t_list* enemies;
t_list* shields;
ship* player;

void level1();

int main(){
    system("cls");

    enemies = new_list();
    shields = new_list();
    
    char** map = create_map(MAX_X_MAP, MAX_Y_MAP);

    initialize_map(map, MAX_X_MAP, MAX_Y_MAP);

    print_map(map, MAX_X_MAP, MAX_Y_MAP);

    level1();

    return 0;
}

void level1(){
    make_invaders(enemies,6,2);
    make_shields(shields,3);
    player = make_player();
    
    draw_invaders(enemies);
    draw_shields(shields);
    
    pthread_t p_movement_invaders;
    pthread_create(&p_movement_invaders,NULL,move_left_right_invaders,enemies);
    pthread_detach(p_movement_invaders);

    pthread_t p_movement_player;
    pthread_create(&p_movement_player,NULL,listen_to_player,player);
    pthread_detach(p_movement_player);

    sleep(1000);
}