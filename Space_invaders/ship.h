#define __SHIP_H__
#ifdef __SHIP_H__

extern const int MAX_X_MAP;
extern const int MAX_Y_MAP;
extern pthread_mutex_t draw_mutex;

const int player_width = 5;
const int player_heigth = 3;

static bool bool_shot = false;

struct t_list;

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
        bool collision_with_any();
        void draw();
        void clean();
};

ship* make_player();
void* listen_to_player(void* void_player);

#endif