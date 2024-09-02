#include <windows.h>
#include <iostream>
#include <unistd.h>
#include "list.h"
#include "shields.h"

void shield::draw(){
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {static_cast<SHORT>(position_x),static_cast<SHORT>(position_y)};
    SetConsoleCursorPosition(hconsole,pos);

    if(health == 6 || health == 5)
        std::cout << "*****   *****";
    else if(health == 4 || health == 3)
        std::cout << "** **   **** ";
    else if(health == 2 || health == 1)
        std::cout << " * **   *  * ";
    else
        std::cout << " *      *  * ";

    pos.X = pos.X + 2;
    pos.Y = pos.Y - 1;

    SetConsoleCursorPosition(hconsole, pos); 

    if(health == 6 || health == 5)
        std::cout << "*********";
    else if(health == 4 || health == 3)
        std::cout << "**** ** *";
    else if(health == 2 || health == 1)
        std::cout << "* ** *  *";
    else
        std::cout << "* *  *  *";
    

    pos.X = pos.X + 3;
    pos.Y = pos.Y - 1;
    
    SetConsoleCursorPosition(hconsole, pos); 

    if(health == 6 || health == 5)
        std::cout << "***";
    else if(health == 4 || health == 3)
        std::cout << "* *";
    else if(health == 2 || health == 1)
        std::cout << "*  ";
    else
        std::cout << "   ";

}

void make_shields(t_list* shield_list, int amount){
    for(int i = 0; i < amount ; i++){
        shield* new_shield = new shield(6+space_inbetween_shields*i , MAX_X_MAP - 6);
        list_add_element(new_shield,shield_list);
    }
}

void draw_shields(t_list* shield_list){
    shield* a_shield = nullptr;
    for(int i = 0; i < shield_list -> elements_count; i++){
        a_shield = (shield*)list_get_element(shield_list,i);
        a_shield ->draw();
    }
}