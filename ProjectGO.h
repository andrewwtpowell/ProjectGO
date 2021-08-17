#pragma once
#include <utility>
#include <vector>


class piece {

    private:
        int p_xPos, p_yPos, p_id, p_color;

    public:
        piece();
        piece(int xPos, int yPos, int id, int color);

        void setColor(int color) { p_color = color; }
        void setID(int id) { p_id = id; }
        void setXPos(int xPos) { p_xPos = xPos; }
        void setYPos(int yPos) { p_yPos = yPos; }

        int const & getXPos() const { return p_xPos; }
        int const & getYPos() const { return p_yPos; }
        int const & getID() const { return p_id; }
        int const & getColor() const { return p_color; }

        bool operator== (const piece &other) const;
        bool operator!= (const piece &other) const;

};

class group {

    private:

        

    public:

        std::vector<piece> pieces;

        group();

        std::vector<piece> getPieces() { return pieces; }
        void addPiece(piece p) { pieces.push_back(p); }
        void combine(group g);

        bool operator== (const group &other) const;
        bool operator!= (const group &other) const;

};

class board {

    private:
        int b_dimension;
        std::vector<group> groups;
        int scores[2] = {0,0};

    public:
        std::vector<std::vector<unsigned char>> places;

        board();
        board(int dimension);

        void setDimension(int dimension) { b_dimension = dimension; }
        bool place(piece p);
        void draw();
        int* evaluate();
        void clear();
        int findSurrounding(int color);
        int calcLiberties(group g);
        void removeGroup(group g);
        group findFriends(group g);
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

        void setColor(int color) { p_color = color; }
        void resetCaptured() { p_captured = 0;}
        void inc_captures(int num) { p_captured+= num; }
        int getColor() { return p_color; }
        int getCaptures() { return p_captured; }

};
