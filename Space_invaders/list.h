#define __LIST_H__
#ifdef __LIST_H__


struct s_nodo{
    void* content;
    s_nodo* next = nullptr;
};

struct t_list{
    s_nodo* head = nullptr;
    int elements_count;
};

//typedef s_nodo t_list;

t_list* new_list(void);
void list_add_element(void* element, t_list* list);
void* list_get_element(t_list* list, unsigned short index);

#endif