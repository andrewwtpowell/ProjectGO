#include "ProjectGO.h"
#include <iostream>

using namespace std;

board::board(int dimension) {
    setDimension(dimension);
}

void board::setDimension(int dimension) {
    b_dimension = dimension;
}

/*
    Draws a board of a variable size in the terminal for the game.
*/
void board::draw() {

    string row = "+";
    row.append(getDimension()-1, '+');

    for(int i = 0; i < getDimension(); i++) {
        cout << row << "\n";
    }
}

bool board::evaluate() {

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

bool player::place(piece p) {

}

int main () {

    //initialize the board
    int size;
    cout << "What size board would you like to play on? (Max: 19)\n";
    cin >> size;
    board b = board(size);
    b.draw();

    //initialize the players
    player p1 = player(0);
    player p2 = player(1);

    //game loop
    //game goes on until both players pass
    while()


    return 0;
}
