#define __MAP__H__
#ifdef __MAP__H__

extern const int MAX_X_MAP;
extern const int MAX_Y_MAP;

char** create_map();
void initialize_map(char** map);
void print_map(char** map);
#endif