#define __SHIELDS_H__
#ifdef __SHIELDS_H__

struct t_list;
const int space_inbetween_shields = 23;

extern const int MAX_X_MAP;
extern const int MAX_Y_MAP;
extern pthread_mutex_t draw_mutex;

class shield{
    public:
        short health=6;
    private:
        int position_x;
        int position_y;
    public:
        shield(int x, int y){ position_x = x; position_y = y;}
        void draw();
};

void make_shields(t_list* shield_list, int amount);
void draw_shields(t_list* shield_list);
#endif 