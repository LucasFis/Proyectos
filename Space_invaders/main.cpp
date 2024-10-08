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

pthread_mutex_t draw_mutex;

void level1();

int main(){
    system("cls");

    pthread_mutex_init(&draw_mutex,NULL);
    enemies = new_list();
    shields = new_list();
    
    char** map = create_map();

    initialize_map(map);

    print_map(map);

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


    while(1){
        random_shots_enemies(enemies);
        usleep(1000000);
    }
    sleep(1000);
}