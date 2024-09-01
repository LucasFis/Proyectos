#include<iostream>
#include "map.h"

char** create_map( unsigned short max_x, unsigned short max_y){
    char** map = new char*[max_x];
    for (int i = 0; i < max_x; ++i) 
        map[i] = new char[max_y];
    
    return map;
}

void initialize_map(char** map, unsigned short MAX_X, unsigned short MAX_Y){

    //CORNERS
    map[0][0] = 201; 
    map[0][MAX_Y-1] = 187; 
    map[MAX_X-1][0] = 200; 
    map[MAX_X-1][MAX_Y-1] = 188; 

    //horizontal row
    for(int i = 1; i < MAX_X-1; i++)
        map[i][0] = 186;

    for(int i = 1; i < MAX_X-1; i++)
        map[i][MAX_Y-1] = 186;

    //vertical row
    for(int i = 1; i < MAX_Y-1; i++)
        map[0][i] = 205;

    for(int i = 1; i < MAX_Y-1; i++)
        map[MAX_X-1][i] = 205;

    //Relleno
    for(int i = 1; i < MAX_X-1; i++)
        for(int j = 1; j < MAX_Y-1; j++)
            map[i][j] = ' ';

}

void print_map(char** map,unsigned short MAX_X, unsigned short MAX_Y){

    for(int i = 0; i < MAX_X; i++){
        for(int j = 0; j < MAX_Y; j++)
            printf("%c",map[i][j]);
        printf("\n");
    }
}