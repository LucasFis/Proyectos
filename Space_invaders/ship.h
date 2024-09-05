#define __SHIP_H__
#ifdef __SHIP_H__

struct t_list;

extern const int MAX_X_MAP;
extern const int MAX_Y_MAP;
extern pthread_mutex_t draw_mutex;
extern t_list* enemies;
extern t_list* shields;

const int player_width = 5;
const int player_heigth = 3;

static bool bool_shot = false;

class ship{
    private:
        int position_x;
        int position_y;
        int health = 5;
    public:
        ship();
        void draw();
        void clean();
        void listen_to_action();
        void shoot();
    private:
        bool collision_test(int x);
};

class bullet{
    private:
        int position_x;
        int position_y;
    public:
        bullet(int x,int y){
            position_x = x; position_y = y;
        }
        int get_x(){return position_x;}
        int get_y(){return position_y;}
        bool collision_with_any(bullet*,t_list*,t_list*);
        void draw(bool up);
        void clean(bool down);
        void destroy(bullet*);
};

ship* make_player();
void* listen_to_player(void* void_player);
static bool collision_with_invader(bullet*,t_list*);
static bool collision_with_shield(bullet*,t_list*);
#endif