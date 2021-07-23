#pragma once
#include <utility>
#include <vector>


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

class group {

    private:

        std::vector<piece> pieces;

    public:

        std::vector<piece> getPieces() { return pieces; }
        void addPiece(piece p);

};

class board {

    private:
        int b_dimension;
        std::vector<group> groups;

    public:
        std::vector<std::vector<unsigned char>> places;

        board(int dimension);

        void setDimension(int dimension);
        bool place(piece p);
        void draw();
        bool evaluate();
        void clear();

        int getDimension() { return b_dimension; }
        std::vector<group> getGroups() { return groups; }
        void addGroup(group g) { groups.push_back(g); }
        

};

class player {

    private:
        int p_captured;
        int p_color;

    public:
        player(int color);

        void setColor(int color);
        void resetCaptured();
        
        void inc_captures(int num) { p_captured+= num; }
        int getColor() { return p_color; }
        int getCaptures() { return p_captured; }

};
