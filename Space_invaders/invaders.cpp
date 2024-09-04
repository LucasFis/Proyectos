#include<windows.h>
#include<iostream>
#include <unistd.h>
#include <pthread.h>
#include"list.h"
#include "invaders.h"

invader::invader(int x, int y){
    position_x = x;
    position_y = y;
}

void invader::draw(){
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {static_cast<SHORT>(position_x),static_cast<SHORT>(position_y)};
    SetConsoleCursorPosition(hconsole, pos); 

    if(health == 3)
        std::cout << "*********";
    else if (health == 2)
        std::cout << "** **  **";
    else std::cout << "*   *  **";

    pos.Y = pos.Y + 1;
    pos.X = pos.X + 1;  

    SetConsoleCursorPosition(hconsole,pos);

    if(health == 3)
        std::cout << "*** ***";
    else if(health == 2)
        std::cout << "* * ***";
    else std::cout << "* *   *";
}

void invader::clean(){
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {static_cast<SHORT>(position_x),static_cast<SHORT>(position_y)};
    SetConsoleCursorPosition(hconsole, pos); 
    std::cout << "         ";
    pos.Y = pos.Y + 1;
    pos.X = pos.X + 1;  
    SetConsoleCursorPosition(hconsole,pos);
    std::cout << "       ";
}

void invader::shoot(){
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {static_cast<SHORT>(position_x+2),static_cast<SHORT>(position_y+2)};
    SetConsoleCursorPosition(hconsole, pos); 
    printf("%c",179);
}

void invader::move(int x, int y){
    pthread_mutex_lock(&draw_mutex);
    clean();

    if(x != 0)
            position_x = position_x + x/abs(x) * 1;
    if(y != 0)
            position_y = position_y + y/abs(y) * 1;
    draw();
    pthread_mutex_unlock(&draw_mutex);
}

bool invader::check_collision_wall(int x , int y){
    int player_x = 0;
    int player_y = 0;

    if(x!=0)
        player_x = position_x + x/abs(x) * 1;
    if(y!=0)
        player_y = position_y + y/abs(y) * 1;

    if(player_x + invader_width >= MAX_Y_MAP || player_x <= 0)
        return true;
    else if(player_y != 0 && (player_y + invader_heigth >= MAX_X_MAP || player_y <= 0))
        return true;
    else return false;
}

void draw_invaders(t_list* enemie_list){
    invader* invasor = nullptr;
    for(int i = 0; i < enemie_list -> elements_count; i++){
        invasor = (invader*)list_get_element(enemie_list,i);
        invasor -> draw();
    }
}

bool check_collision_all_enemies(t_list* enemie_list,int x, int y){
    invader* invasor = nullptr;
    bool value;

    for(int i = 0; i < enemie_list -> elements_count; i++){
        invasor = (invader*)list_get_element(enemie_list,i);

        if((value = invasor -> check_collision_wall(x,y)))
            return value;    
    }
    return false;
}

bool move_invaders(t_list* enemie_list, int x, int y){
    invader* invasor = nullptr;

    if(!check_collision_all_enemies(enemie_list, x, y)){
        for(int i = 0; i < enemie_list -> elements_count; i++){
            invasor = (invader*)list_get_element(enemie_list,i);
            invasor -> move(x,y);
        }
        return true;
    }
    return false;
}

void make_invaders(t_list* enemies, int x_amount, int y_amount){
    for(int j = 0; j < y_amount; j++)
        for(int i = 0; i < x_amount; i++){
            invader* invasor = new invader(1+space_inbetween_invader*i,1 + (1 + invader_heigth)*j);
            list_add_element(invasor, enemies);
        }
}

void* move_left_right_invaders(void* void_enemies){
    t_list* enemies = (t_list*) void_enemies;
    bool change_direction = true;
    bool mov_value = true;
    while(1){
        
        if(!change_direction)
            mov_value = !mov_value;
        if(mov_value){
            change_direction = move_invaders(enemies, 2, 0);
            usleep(305000);
        }
        else{
            change_direction = move_invaders(enemies, -2, 0);
            usleep(305000);
        }

    }
    return NULL;
}

t_hitbox* invader::front_hitbox(){
    t_hitbox* new_hitbox = (t_hitbox*) malloc(sizeof(t_hitbox));
    new_hitbox -> y_value = position_y;
    new_hitbox -> x_values = (int*) malloc(invader_width);
    for(int i = 0; i < invader_width ; i++)
        new_hitbox -> x_values[i] = this -> position_x + i;

    return new_hitbox;
}

void invader::destroy(invader* invasor,t_list* enemies){
    list_delete_element(enemies,invasor);
    invasor -> clean();
    free(invasor);
}

bool compare_positions(int* vector, t_hitbox* hitbox_to_test){
    if(vector[1] == hitbox_to_test ->y_value)
        for(int j = 0; j < invader_width ; j++)
                if(vector[0]==hitbox_to_test -> x_values[j])
                    return true;
    return false;
}