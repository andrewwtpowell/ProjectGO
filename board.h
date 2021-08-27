#pragma once
#include "group.h"
#include <utility>
#include <vector>

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
        int findSurrounding(std::vector<std::vector<bool>> &visited, int x, int y, int color);
        int calcLiberties(group g);
        void removeGroup(group g);
        group findFriends(group g);
        int getDimension() { return b_dimension; }
        std::vector<group> getGroups() { return groups; }
        void addGroup(group g) { groups.push_back(g); }
        

};