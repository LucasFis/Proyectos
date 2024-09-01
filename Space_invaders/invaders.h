#define __INVADER__H__
#ifdef __INVADER__H__

struct t_list;
const unsigned short space_inbetween_invader = 11;

class invader{
    private:
        int position_x;
        int position_y;
    public:
        invader(int x, int y);
        void draw();
        void move(int x,int y);
        void clean();
        void shoot();
};

void draw_invaders(t_list* enemie_list);

#endif