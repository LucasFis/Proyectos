#define __INVADER__H__
#ifdef __INVADER__H__

struct t_list;
const unsigned short space_inbetween_invader = 11;
const int invader_width = 9;
const int invader_heigth = 2;

extern const int MAX_X_MAP;
extern const int MAX_Y_MAP;
extern pthread_mutex_t draw_mutex;

typedef struct{
    int* x_values = nullptr;
    int y_value;
}t_hitbox;

class invader{
    public:
        int health = 3;
    private:
        int position_x;
        int position_y;
    public:
        invader(int x, int y);
        void draw();
        void move(int x,int y);
        void clean();
        void shoot();
        bool check_collision_wall(int, int);
        t_hitbox* front_hitbox();
};

void make_invaders(t_list* enemies, int x_amount, int y_amount);
void draw_invaders(t_list* enemie_list);
bool move_invaders(t_list* enemie_list, int x, int y);
void* move_left_right_invaders(void* void_enemies);
bool compare_positions(int* , t_hitbox*);
#endif