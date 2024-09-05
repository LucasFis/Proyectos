#define __INVADER__H__
#ifdef __INVADER__H__
#include "utility.h"


struct t_list;
const unsigned short space_inbetween_invader = 11;
const int invader_width = 9;
const int invader_heigth = 2;

extern const int MAX_X_MAP;
extern const int MAX_Y_MAP;
extern pthread_mutex_t draw_mutex;

class invader{
    public:
        int health = 3;
    private:
        int position_x;
        int position_y;
    public:
        invader(int x, int y);
        int get_y(){return position_y;};
        int get_x(){return position_x;};
        void draw();
        void move(int x,int y);
        void clean();
        void shoot();
        bool check_collision_wall(int, int);
        t_hitbox* front_hitbox();
        void destroy(invader*, t_list*);
};

void make_invaders(t_list* enemies, int x_amount, int y_amount);
void draw_invaders(t_list* enemie_list);
bool move_invaders(t_list* enemie_list, int x, int y);
void* move_left_right_invaders(void* void_enemies);
bool compare_positions(int* , t_hitbox*,int);
t_list* enemies_lower_row(t_list* complete_list);
void random_shots_enemies(t_list* enemies);
#endif