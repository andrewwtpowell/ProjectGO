#include "ProjectGO.h"
#include <iostream>

using namespace std;

board::board(int dimension) {
    setDimension(dimension);
}

void board::setDimension(int dimension) {
    b_dimension = dimension;
}

void board::draw() {

}

void board::evaluate() {

}

void board::clear() {

}

piece::piece(int xPos, int yPos, int id, int color) {
    setXPos(xPos);
    setYPos(yPos);
    setID(id);
    setColor(color);
}

void piece::setColor(int color) {
    p_color = color;
}

void piece::setID(int id) {
    p_id = id;
}

void piece::setXPos(int xPos) {
    p_xPos = xPos;
}

void piece::setYPos(int yPos) {
    p_yPos = yPos;
}

player::player(int color) {
    setColor(color);
    resetCaptured();
}

void player::setColor(int color) {
    p_color = color;
}

void player::resetCaptured() {
    p_captured = 0;
}

void player::capture() {
    p_captured++;
}
