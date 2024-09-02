#include<windows.h>
#include<iostream>
#include<math.h>
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
    std::cout << "*********";
    pos.Y = pos.Y + 1;
    pos.X = pos.X + 1;  
    SetConsoleCursorPosition(hconsole,pos);
    std::cout << "*** ***";
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
    clean();

    if(x != 0)
            position_x = position_x + x/abs(x) * 1;
    if(y != 0)
            position_y = position_y + y/abs(y) * 1;

    draw();
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

void move_invaders(t_list* enemie_list, int x, int y){
    invader* invasor = nullptr;

    if(!check_collision_all_enemies(enemie_list, x, y))
        for(int i = 0; i < enemie_list -> elements_count; i++){
            invasor = (invader*)list_get_element(enemie_list,i);
            invasor -> move(x,y);
        }
}