#include <windows.h>
#include <iostream>
#include <conio.h>
#include <unistd.h>
#include "ship.h"

void ship::draw(){
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {static_cast<SHORT>(position_x),static_cast<SHORT>(position_y)};
    SetConsoleCursorPosition(hconsole, pos); 

    if(health == 5 || health == 4)
        std::cout << "**";
    else if (health == 3 || health == 2)
        std::cout << "**";
    else std::cout << "* ";

    pos.Y = pos.Y + 1;
    pos.X = pos.X - 1;  

    SetConsoleCursorPosition(hconsole,pos);

    if(health == 5 || health == 4)
        std::cout << "****";
    else if(health == 3 || health == 2)
        std::cout << "** *";
    else std::cout << " * *";

    pos.Y = pos.Y + 1;
    pos.X = pos.X - 1;  

    SetConsoleCursorPosition(hconsole,pos);

    if(health == 5 || health == 4)
        std::cout << "**  **";
    else if(health == 3 || health == 2)
        std::cout << "*   **";
    else std::cout << "*  * ";
}

void ship::clean(){
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {static_cast<SHORT>(position_x),static_cast<SHORT>(position_y)};
    SetConsoleCursorPosition(hconsole, pos); 

    std::cout << "   ";

    pos.Y = pos.Y + 1;
    pos.X = pos.X - 1;  

    SetConsoleCursorPosition(hconsole,pos);

    std::cout << "     ";

    pos.Y = pos.Y + 1;
    pos.X = pos.X - 1;  

    SetConsoleCursorPosition(hconsole,pos);

    std::cout << "       ";
}

void ship::listen_to_action(){
    char character;

    while(1){
        usleep(100000);
        character = getch();
        clean();
        switch(character){
            case 'a':
            case 'A':
                if(!collision_test(-1))
                    position_x = position_x - 1;
                break;
            case 'd':
            case 'D':
                if(!collision_test(1))
                    position_x = position_x + 1;
                break;
        }
        draw();
    }
}

bool ship::collision_test(int x){
    int player_x = 0;

    if(x!=0)
        player_x = position_x + x/abs(x) * 1;

    if(player_x + player_width >= MAX_Y_MAP || player_x <= player_width - 3)
        return true;
    else return false;
}

ship* make_player(){
    ship* new_player = new ship();
    
    new_player ->draw();

    return new_player;
}

void* listen_to_player(void* void_player){
    ship* player = (ship*) void_player;
    player -> listen_to_action();

    return NULL;
}