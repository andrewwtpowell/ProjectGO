#pragma once
#include <utility>
#include <vector>

class board {

    private:
        int b_dimension;
        std::vector<std::vector<unsigned char>> places;

    public:
        board(int dimension);

        void setDimension(int dimension);
        void draw();
        bool evaluate();
        void clear();

        int getDimension() { return b_dimension; }

};

class piece {

    private:
        int p_xPos, p_yPos, p_id, p_color;

    public:
        piece(int xPos, int yPos, int id, int color);

        void setColor(int color);
        void setID(int id);
        void setXPos(int xPos);
        void setYPos(int xPos);

        int getXPos() { return p_xPos; }
        int getYPos() { return p_yPos; }
        int getID() { return p_id; }
        int getColor() { return p_color; }

};

class player {

    private:
        int p_captured;
        int p_color;

    public:
        player(int color);

        void place();
        void setColor(int color);
        void resetCaptured();
        void capture();
        bool place(piece p);

        int getColor() { return p_color; }
        int getCaptures() { return p_captured; }

};