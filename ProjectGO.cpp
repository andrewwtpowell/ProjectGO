#include "ProjectGO.h"
#include <iostream>

using namespace std;

board::board(int dimension) {

    setDimension(dimension);

    //initialize 2D vector for each place on the board
    places.resize(dimension);
    for(int i = 0; i < dimension; i++)
        places[i].resize(dimension);

}

void board::setDimension(int dimension) {
    b_dimension = dimension;
}


//Draws a board of a variable size in the terminal for the game.
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

bool board::place(piece p) {
    
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

    //player move coordinate variables
    int p1_move_x = -1;
    int p1_move_y = -1;
    int p2_move_x = -1;
    int p2_move_y = -1;

    //game loop
    //game goes on until both players pass
    bool endgame = false;
    while(!endgame) {

        //find all captures 
        //iterate through 2D vector for board
        for(int i = 0; i < b.places.size(); i++) {
            for(int j = 0; b.places[i].size(); j++) {
                //
            }
        }
        //  every time you come across a piece check the four adjacent pieces to see if it has been captured
        //  i.e. piece at x=2, y=1 -> check (1,1), (2,2), (3,1)
        //  if all adjacent have a piece then the piece is captured and the opposing player gets its captures incremented

        //find legal spaces to move (or illegal spaces)

        //draw board with moves from last board iteration

        //trigger player 1 to place a piece
        //player 1 places a piece or passes
        cout << "Player 1 enter the x coordinate of your move (enter -1 to pass)\n";
        cin >> p1_move_x;
        cout << "Player 1 enter the y coordinate of your move (enter -1 to pass)\n";
        cin >> p1_move_y;

        //trigger player 2 to place a piece
        //player 2 places a piece or passes
        cout << "Player 2 enter the x coordinate of your move (enter -1 to pass)\n";
        cin >> p2_move_x;
        cout << "Player 2 enter the y coordinate of your move (enter -1 to pass)\n";
        cin >> p2_move_y;

        //check if both players passed. If so, endgame = true
        if((p1_move_x == -1 || p1_move_y == -1) && (p2_move_x == -1 || p2_move_y == -1)) {
            endgame = true;
            break;
        }

        //check if players moves are within the grid
        if(p1_move_x < 0 || p1_move_x > size || p1_move_y < 0 || p1_move_y > size || p2_move_x < 0 || p2_move_x > size || p2_move_y < 0 || p2_move_y > size) {
            //require a new move to be played
        }

    }

    //evaluate the board to determine final score


    return 0;
}
