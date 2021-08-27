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