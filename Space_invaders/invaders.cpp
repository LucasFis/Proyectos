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

void draw_invaders(t_list* enemie_list){
    for(int i = 0; i < enemie_list -> elements_count; i++){
        invader invasor = *(invader*)list_get_element(enemie_list,i);
        invasor.draw();
    }
}
