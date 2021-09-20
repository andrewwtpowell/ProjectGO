#include "piece.h"

piece::piece() {
    p_xPos = -1;
    p_yPos = -1;
    p_id = -1;
    p_color = -1;
}

piece::piece(int xPos, int yPos, int id, int color) {
    p_xPos = xPos;
    p_yPos = yPos;
    p_id = id;
    p_color = color;
}

bool piece::operator== (const piece &other) const {
    if((*this).p_color == other.p_color 
    && (*this).p_id == other.p_id
    && (*this).p_xPos == other.p_xPos
    && (*this).p_yPos == other.p_yPos)
        return true;
    else   
        return false;
}

bool piece::operator!= (const piece &other) const {
    return !(*this == other);
}