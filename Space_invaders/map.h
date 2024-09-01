#define __MAP__H__
#ifdef __MAP__H__

char** create_map(unsigned short max_x, unsigned short max_y);
void initialize_map(char** map, unsigned short max_x, unsigned short max_y);
void print_map(char** map, unsigned short MAX_X, unsigned short MAX_Y);
#endif