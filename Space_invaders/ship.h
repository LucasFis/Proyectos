#define __SHIP_H__
#ifdef __SHIP_H__

extern const int MAX_X_MAP;
extern const int MAX_Y_MAP;

const int player_width = 5;
const int player_heigth = 3;

class ship{
    private:
        int position_x;
        int position_y;
        int health = 5;
    public:
        ship(){
            position_x = 4;
            position_y = MAX_X_MAP - 4;
        }
        void draw();
        void clean();
        void listen_to_action();
    private:
        bool collision_test(int x);
};

ship* make_player();
void* listen_to_player(void* void_player);

#endif