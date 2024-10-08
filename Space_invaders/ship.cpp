#include <windows.h>
#include <iostream>
#include <conio.h>
#include <unistd.h>
#include "ship.h"
#include "invaders.h"
#include "list.h"
#include "shields.h"

static void* animate_shoot(void* nothing);

pthread_t p_bullet;

ship::ship(){
    position_x = 4;
    position_y = MAX_X_MAP - 4;
}

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
        usleep(200000);
        character = getch();
        
        switch(character){
            case 'a':
            case 'A':
                if(!collision_test(-1)){
                    pthread_mutex_lock(&draw_mutex);
                    clean();
                    position_x = position_x - 2;
                    draw();
                    pthread_mutex_unlock(&draw_mutex);
                }
                break;
            case 'd':
            case 'D':
                if(!collision_test(1)){
                    pthread_mutex_lock(&draw_mutex);
                    clean();
                    position_x = position_x + 2;
                    draw();
                    pthread_mutex_unlock(&draw_mutex);
                }
                break;
            case 'w':
            case 'W':
                if(!bool_shot){
                    bool_shot = true;
                    shoot();
                }
                break;
        }
        
        
    }
}

bool ship::collision_test(int x){
    int player_x = 0;

    if(x!=0)
        player_x = position_x + x/abs(x) * 1;

    if(player_x + player_width >= MAX_Y_MAP || player_x <= player_width - 2)
        return true;
    else return false;
}

void ship::shoot(){

    bullet* new_bullet = new bullet(position_x + 1,position_y - 1);

    pthread_create(&p_bullet, NULL, animate_shoot,new_bullet);
    pthread_detach(p_bullet);
}

void bullet::draw(bool up){
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {static_cast<SHORT>(position_x),static_cast<SHORT>(position_y)};
    SetConsoleCursorPosition(hconsole, pos);
    printf("%c",179);
    if(up)
        position_y--;
    else position_y++;
}

void bullet::clean(bool down){
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int pos_y = 0;
    if(down)
    pos_y = position_y + 1;
    else pos_y = position_y - 1;
    COORD pos = {static_cast<SHORT>(position_x),static_cast<SHORT>(pos_y)};
    SetConsoleCursorPosition(hconsole, pos);
    printf(" ");
}

static void* animate_shoot(void* void_bullet){
    bullet* new_bullet = (bullet*) void_bullet;

    while(new_bullet->get_y() <= MAX_X_MAP && new_bullet->get_y() != 0){
        pthread_mutex_lock(&draw_mutex);
        new_bullet->draw(true);
        pthread_mutex_unlock(&draw_mutex);
        usleep(60000); 
        new_bullet->clean(true);
        new_bullet->collision_with_any(new_bullet, enemies,shields);
        if(!bool_shot)
            goto end;
    }

    bool_shot = false;
    end:

    free(new_bullet);
    return NULL;
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

bool bullet::collision_with_any(bullet* new_bullet,t_list* enemies, t_list* shields){
    bool collision_invader =  collision_with_invader(new_bullet, enemies);
    bool collision_shield = collision_with_shield(new_bullet, shields);
    return collision_invader || collision_shield;
}

void bullet::destroy(bullet* bullet_to_destroy){
    pthread_cancel(p_bullet);
    bool_shot = false;
}

static bool collision_with_invader(bullet *to_test, t_list* enemies){
    int vector[2] = { to_test -> get_x(), to_test ->get_y() };
    bool final_value = false;
    t_hitbox* hitbox_invader = nullptr;

    for(int i = 0; i < enemies -> elements_count && bool_shot ;i++){
        invader* invasor = (invader*)list_get_element(enemies,i);
        hitbox_invader = invasor -> front_hitbox();

        final_value = compare_positions(vector, hitbox_invader,invader_width);
        
        if(final_value){
            invasor -> health -= 1; 
            to_test -> destroy(to_test);
            if(invasor -> health <= 0)
                invasor -> destroy(invasor,enemies);
        }

        free(hitbox_invader);
    }
    
    return final_value;
}

static bool collision_with_shield(bullet* to_test, t_list* shields){
    int vector[2] = { to_test -> get_x(), to_test ->get_y() };
    bool final_value = false;
    t_hitbox* hitbox_shield = nullptr;

    for(int i = 0; i < shields -> elements_count && bool_shot ;i++){
        shield* hitted_shield = (shield*)list_get_element(shields,i);
        hitbox_shield = hitted_shield -> bottom_hitbox();

        final_value = compare_positions(vector, hitbox_shield, shield_width);
        
        if(final_value){
            hitted_shield -> health -= 1; 
            to_test -> destroy(to_test);
            hitted_shield -> draw();
            if(hitted_shield -> health <= 0)
                hitted_shield -> destroy(hitted_shield,shields);
        }
        free(hitbox_shield);
    }
    return final_value;
}



