#include<iostream>
#include "map.h"

char** create_map(){
    char** map = new char*[MAX_X_MAP];
    for (int i = 0; i < MAX_X_MAP; ++i) 
        map[i] = new char[MAX_Y_MAP];
    
    return map;
}

void initialize_map(char** map){

    //CORNERS
    map[0][0] = 201; 
    map[0][MAX_Y_MAP-1] = 187; 
    map[MAX_X_MAP-1][0] = 200; 
    map[MAX_X_MAP-1][MAX_Y_MAP-1] = 188; 

    //horizontal row
    for(int i = 1; i < MAX_X_MAP-1; i++)
        map[i][0] = 186;

    for(int i = 1; i < MAX_X_MAP-1; i++)
        map[i][MAX_Y_MAP-1] = 186;

    //vertical row
    for(int i = 1; i < MAX_Y_MAP-1; i++)
        map[0][i] = 205;

    for(int i = 1; i < MAX_Y_MAP-1; i++)
        map[MAX_X_MAP-1][i] = 205;

    //Relleno
    for(int i = 1; i < MAX_X_MAP-1; i++)
        for(int j = 1; j < MAX_Y_MAP-1; j++)
            map[i][j] = ' ';

}

void print_map(char** map){

    for(int i = 0; i < MAX_X_MAP; i++){
        for(int j = 0; j < MAX_Y_MAP; j++)
            printf("%c",map[i][j]);
        printf("\n");
    }
}