#include<cstdlib>
#include<iostream>
#include "map.h"
#include "invaders.h"
#include "ship.h"
#include "list.h"

t_list* new_list(void){
    t_list* new_list = (t_list*)malloc(sizeof(t_list));
    if (new_list != nullptr) {
        new_list->head = nullptr;
        new_list->elements_count = 0;
    }
    return new_list;
}

void list_add_element(void* element, t_list* list){
    s_nodo* data = list -> head;
    bool head_is_null = true;
    int index=0;
    for(int i=0; i < list -> elements_count && data != nullptr ; i++){
        head_is_null = false;
        data = data -> next;
        index++;
    }
    if(data!=nullptr)
        std::cout << "ERROR\n";

    data = (s_nodo*)malloc(sizeof(s_nodo));

    data -> content = element;
    data -> next = nullptr;

    if(head_is_null)
        list -> head = data;
    else{
        s_nodo* aux = list ->head;
        for(int i = 0; i < index - 1; i++)
            aux = aux -> next;
        aux -> next = data;
    }
    list -> elements_count++;
}

void* list_get_element(t_list* list, unsigned short index){
    s_nodo* data = list -> head; 
    for(int i=0 ; i < index && data -> next != NULL; i++){
        data = data -> next;
    }
    return data -> content;
}
