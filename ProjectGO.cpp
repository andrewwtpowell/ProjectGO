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

    //iterate through board
    for(int i = 0; i < places.size(); i++) {
        for(int j = 0; j < places[i].size(); i++) {
            //print + for no piece, W for white piece, B for black piece
            if(places[i][j] == 0) {
                cout << "+";
            }
            else if(places[i][j] == 1) {
                cout << "W";
            }
            else if(places[i][j] == 2) {
                cout << "B";
            }
        }
        cout << "\n";
    }
}

bool board::evaluate() {
    return true;
}

void board::clear() {

}

bool board::place(piece p) {
    return true;
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

void group::addPiece(piece p) {

    pieces.push_back(p);

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


void checkLiberties(piece p) {

}

group checkForCaptures(piece p) {

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

    //initialize player moves, turn tracker, pass tracker, turn counter
    int p_move_x = -1;
    int p_move_y = -1;
    bool p1_turn = true;
    bool p1_pass = false;
    bool p2_pass = false;
    int turn_counter = 0;

    //new algorithm
    /*
        Trigger player whose turn it is to move (keep a variable to determine whose move it is)

        If player passes and other player passed the move previously -> game over -> trigger evaluation of board
        (Keep variable for when one player passes)

        Check to make sure the move played is 
        -> within the grid
        -> in a place that did not previously have a piece in it
        
        Check liberties of the piece

        If there is a piece of the same color in one of the liberties
        -> create a "group" if the piece it is connected to does not already have one
        -> otherwise add the newly placed piece to the group of the connected piece

        Check liberties of the entire group (this step might not be necessary - very unlikely that a piece will be played that would cause itself to be captured)
        -> iterate through group
        -> if none of the pieces in the group have an open liberty then the group is captured
        
        Check liberties of any group or piece of the opposing color that the placed piece touches
        -> if there is an opposing piece in any of the liberties of the placed piece, check to see if that opposing piece is part of a group
        -> if the adjacent opposing piece is not part of a group, check its liberties - if occupied, capture piece
        -> if the adjacent opposing piece is part of a group, iterate through each piece in the group checking liberties - if all occupied, capture group
        ************
        set a capture variable to true
        iterate through pieces in group
            if any of the pieces have an open liberty
                capture variable = false
                break loop
        if loop completes without breaking the group is captured
        ************


    */

    //game loop
    //game loops until both players pass
    while(!p1_pass && !p2_pass) {

        turn_counter++;

        bool legalMove = false;

        //loop until valid move is played
        while(!legalMove) {

            p_move_x = -1;
            p_move_y = -1;

            //Trigger player whose turn it is to move
            if(p1_turn) {

                cout << "Player 1 enter the x coordinate of your move. To pass hit enter.\n";
                cin >> p_move_x;
                cout << "Player 1 enter the y coordinate of your move. To pass hit enter.\n";
                cin >> p_move_y;

                //check to make sure the move is legal -> within grid + not already occupied
                legalMove = false;
                if(p_move_x >= 0 && p_move_x <= b.getDimension() && p_move_y >= 0 && p_move_y <= b.getDimension() && b.places[p_move_x][p_move_y] == 0)
                    legalMove = true;

                //if x and y == -1 -> player passed
                if(p_move_x == -1 && p_move_y == -1) {
                    p1_pass = true;
                    legalMove = true;
                }

            }   
            else {

                cout << "Player 2 enter the x coordinate of your move. To pass hit enter.\n";
                cin >> p_move_x;
                cout << "Player 2 enter the y coordinate of your move. To pass hit enter.\n";
                cin >> p_move_y;

                //check to make sure the move is legal -> within grid + not already occupied
                legalMove = false;
                if(p_move_x >= 0 && p_move_x <= b.getDimension() && p_move_y >= 0 && p_move_y <= b.getDimension() && b.places[p_move_x][p_move_y] == 0)
                    legalMove = true;

                //if x and y == -1 -> player passed
                if(p_move_x == -1 && p_move_y == -1) {
                    p2_pass = true;
                    legalMove = true;
                }

            }
        }

        //create piece for move just played
        piece p = piece(0,0,0,0);
        if(p1_turn)
            p = piece(p_move_x,p_move_y,turn_counter,0);
        else
            p = piece(p_move_x,p_move_y,turn_counter,1);

        b.place(p);


        //check liberties of piece just played
        checkLiberties(p);

        //check for captures made by piece
        group captured = checkForCaptures(p);

        //remove captured pieces/group from board

        //increment captures for player
        if(p1_turn)
            p1.inc_captures(captured.getPieces().size());
        else
            p2.inc_captures(captured.getPieces().size());
        


        //switch flag for player turn
        p1_turn = !p1_turn;

    }
    


    //to do
    /*
        Create Group class
            What functions/variables needed in this class?
                array/vector of pieces
                function to add a piece to a group
        
        Create checkLegalMove function to determine if the most recent move is legal

        Create checkLiberties funciton to check liberties of a piece/group touched by the most recent placed piece/group
    */


    /*

    //OLD ALGORITHM

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
            for(int j = 0; i < b.places[i].size(); j++) {
                //detect a white piece
                if(b.places[i][j] == 1) {
                    //check for surrounding black pieces

                    //Left Edge Case -> i==0
                    if(i == 0) {

                        //Top Left Case -> (0,0)
                        if(j == 0) {
                            //Check (1,0) and (0,1)
                            if(b.places[1][0] == 2 && b.places[0][1] == 2) {
                                //Capture for black
                            }
                        }
                        //Bottom Left Case -> (0, Max)
                        else if (j == b.places[i].size()-1) {
                            //Check (0,Max-1) and (1,Max)
                            if(b.places[0][b.getDimension()-1] == 2 && b.places[1][b.getDimension()]) {
                                //Capture for black
                            }
                        }
                        else {
                            
                            if(b.places[1][j] == 2 && b.places[0][j-1] == 2 && b.places[0][j+1] == 2) {
                                //Capture for black
                            }
                        }
                    }

                    //Right Edge Case -> i==Max
                    else if(i == b.places.size()-1) {

                        //Top Right Case -> (Max,0)
                        if(j == 0) {
                            //Check (Max-1,0) and (Max,1)
                            if(b.places[b.getDimension()-1][0] == 2 && b.places[b.getDimension()][1] == 2) {
                                //Capture for black
                            }

                        }
                        //Bottom Right Case -> (Max, Max)
                        if(j == b.places[i].size()-1) {
                            //Check (Max-1,Max) and (Max,Max-1)
                            if(b.places[b.getDimension()-1][b.getDimension()] == 2 && b.places[b.getDimension()][b.getDimension()-1] == 2) {
                                //Capture for black
                            }

                        }
                        else {

                        }
                    }

                    //Top Edge Case -> j==0
                    else if(j == 0) {

                    }

                    //Bottom Edge Case -> j==Max
                    else if(j == b.places[i].size()-1) {

                    }

                    //All other cases
                    else {

                    }
                }

                //detect a black piece
                else if(b.places[i][j] == 2) {
                    //check for surrounding white pieces
                }
            }
        }
        //  every time you come across a piece check the four adjacent pieces to see if it has been captured
        //  i.e. piece at x=2, y=1 -> check (1,1), (2,2), (3,1), (2,0)
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
        */

}
