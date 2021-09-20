#ifndef PLAYER_H
#define PLAYER_H

class player {

    private:
        int p_captured;
        int p_color;

    public:
        player(int color) { p_captured = 0; p_color = color; };

        void setColor(int color) { p_color = color; }
        void resetCaptured() { p_captured = 0;}
        void inc_captures(int num) { p_captured+= num; }
        int getColor() { return p_color; }
        int getCaptures() { return p_captured; }

};

#endif