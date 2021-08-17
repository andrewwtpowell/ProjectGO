#include "ProjectGO.h"
#include <iostream>
#include <algorithm>

using namespace std;

/*

Order of Operations:

1. Player Class 
2. Piece Class
3. Group Class
4. Board Class
5. Remaining Functionality
6. Game Loop Algorithm

*/

player::player(int color) {
    p_captured = 0;
    p_color = color;
}

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

group::group() {

    pieces.resize(0);
}

void group::combine(group g) {

    //preallocate memory
    pieces.reserve(pieces.size() + g.pieces.size());

    //insert contents of group g at the end of this group's vector
    pieces.insert(pieces.end(), g.pieces.begin(), g.pieces.end());

}

bool group::operator== (const group &other) const {

    for(int i = 0; i < (*this).pieces.size(); i++) {
        if((*this).pieces[i] != other.pieces[i])
            return false;
    }
    return true;
    
}

bool group::operator!= (const group &other) const {
    return !(*this == other);
}

board::board() {

    b_dimension = 9;

    //initialize 2D vector for each place on the board
    places.resize(b_dimension);
    for(int i = 0; i < b_dimension; i++)
        places[i].resize(b_dimension);

}

board::board(int dimension) {

    b_dimension = dimension;

    //initialize 2D vector for each place on the board
    places.resize(b_dimension);
    for(int i = 0; i < b_dimension; i++)
        places[i].resize(b_dimension);

}

bool board::place(piece p) {

    //check to see if there is a piece that already exists in the location
    if(places[p.getXPos()][p.getYPos()] == 0) {

        //place piece on board
        places[p.getXPos()][p.getYPos()] = p.getColor();

        return true;
    }
    else 
        return false;
        
}

void board::draw() {

    //iterate through board
    for(int i = 0; i < places.size(); ++i) {
        for(int j = 0; j < places[i].size(); ++j) {
            //print + for no piece, W for white piece, B for black piece
            if(places[i][j] == 0) {
                cout << "+ ";
            }
            else if(places[i][j] == 1) {
                cout << "W ";
            }
            else if(places[i][j] == 2) {
                cout << "B ";
            }
        }
        cout << "\n";
    }

}

int* board::evaluate() {

    //game is scored based on number of pieces each player has on the board
    // + number of empty points that a player's pieces surround

    //count up number of pieces each player has on the board 
    for(int i = 0; i < places.size()-1; i++) {
        for(int j = 0; j < places[i].size()-1; j++) {
            //increment player score for each piece found
            if(places[i][j] == 1)
                scores[0]++;
            else if(places[i][j] == 2)
                scores[1]++;
        }
    }

    //find places that a player's pieces surround



    return scores;
}

void board::clear() {

    //iterate through board vector and set all to zero
    for(int i = 0; i < places.size(); i++) {
        for(int j = 0; j < places[i].size(); j++) {
            places[i][j] = 0;
        }
    }

}

int board::findSurrounding(int color) {
    return 0;
}

//Find liberties for a group (if any)
int board::calcLiberties(group g) {
    
    int x, y;
    int libs = 0;
    //iterate through pieces in group
    for(vector<piece>::iterator itr = g.pieces.begin(); itr != g.pieces.end(); ++itr) {

        //bounds checking
        x = (*itr).getXPos()-1;
        y = (*itr).getYPos();
        if(x >= 0 && x < b_dimension && y >= 0 && y < b_dimension) {

            //check for liberty (open adjacent space)
            if(places[x][y] < 1)
                libs++;
        }

        //bounds checking
        x = (*itr).getXPos()+1;
        y = (*itr).getYPos();
        if(x >= 0 && x < b_dimension && y >= 0 && y < b_dimension) {

            if(places[x][y] < 1)
                libs++;
        }

        //bounds checking
        x = (*itr).getXPos();
        y = (*itr).getYPos()+1;
        if(x >= 0 && x < b_dimension && y >= 0 && y < b_dimension) {

            if(places[x][y] < 1)
                libs++;
        }

        //bounds checking
        x = (*itr).getXPos();
        y = (*itr).getYPos()-1;
        if(x >= 0 && x < b_dimension && y >= 0 && y < b_dimension) {

            if(places[x][y] < 1)
                libs++;
        }
    }
    return libs;
}

void board::removeGroup(group g) {

    //remove group from group vector
    groups.erase(remove(groups.begin(), groups.end(), g), groups.end());

    //update board vector 
    for(vector<piece>::iterator itr = g.pieces.begin(); itr != g.pieces.end(); ++itr) {
        places[(*itr).getXPos()][(*itr).getYPos()] = 0;
    }

}

group board::findFriends(group g) {

    group friend_group = group();
    int index = -1;
    vector<piece>::iterator itr;
    int x, y, color;

    //iterate through pieces in group looking for a similar color, adjacent group
    for(itr = g.pieces.begin(); itr != g.pieces.end(); ++itr) {

        x = (*itr).getXPos()-1;
        y = (*itr).getYPos();
        color = (*itr).getColor();

        //check to ensure we are in bounds of 2D board vector
        if(x >= 0 && x < this->getDimension() && y >= 0 && y < this->getDimension()) {

            //check for adjacent pieces with same color
            if(places[x][y] == color) {

                //get group of same colored piece
                //iterate through groups
                for(vector<group>::iterator itr_g = groups.begin(); itr_g != groups.end(); ++itr_g) {

                    //iterate through pieces in groups
                    for(vector<piece>::iterator itr_p = (*itr_g).pieces.begin(); itr_p != (*itr_g).pieces.end(); ++itr_p) {

                        //find friend again
                        if((*itr_p).getXPos() == x && (*itr_p).getYPos() == y) {
                            friend_group = (*itr_g);
                            index = itr_g - groups.begin();
                        }
                    }
                }

                //combine input group with found group
                g.combine(friend_group);

                //remove found group from vector of groups
                groups.erase(groups.begin() + index);

                //remove initial group from vector of groups
                groups.erase(groups.end());

                //add new combined group to vector of groups
                groups.push_back(g);

                //return combined group
                return g;
                
            }
        }

        x = (*itr).getXPos()+1;
        y = (*itr).getYPos();

        //check to ensure we are in bounds of 2D board vector
        if(x >= 0 && x < this->getDimension() && y >= 0 && y < this->getDimension()) {

            if(places[x][y] == color) {

                //get group of same colored piece
                //iterate through groups
                for(vector<group>::iterator itr_g = groups.begin(); itr_g != groups.end(); ++itr_g) {

                    //iterate through pieces in groups
                    for(vector<piece>::iterator itr_p = (*itr_g).pieces.begin(); itr_p != (*itr_g).pieces.end(); ++itr_p) {

                        //find friend again
                        if((*itr_p).getXPos() == x && (*itr_p).getYPos() == y) {
                            friend_group = (*itr_g);
                            index = itr_g - groups.begin();
                        }
                    }
                }

                //combine input group with found group
                g.combine(friend_group);

                //remove found group from vector of groups
                groups.erase(groups.begin() + index);

                //remove initial group from vector of groups
                groups.erase(groups.end());

                //add new combined group to vector of groups
                groups.push_back(g);

                //return combined group
                return g;
            }
        }

        x = (*itr).getXPos();
        y = (*itr).getYPos()+1;

        //check to ensure we are in bounds of 2D board vector
        if(x >= 0 && x < this->getDimension() && y >= 0 && y < this->getDimension()) {

            if(places[x][y] == color) {

                //get group of same colored piece
                //iterate through groups
                for(vector<group>::iterator itr_g = groups.begin(); itr_g != groups.end(); ++itr_g) {

                    //iterate through pieces in groups
                    for(vector<piece>::iterator itr_p = (*itr_g).pieces.begin(); itr_p != (*itr_g).pieces.end(); ++itr_p) {

                        //find friend again
                        if((*itr_p).getXPos() == x && (*itr_p).getYPos() == y) {
                            friend_group = (*itr_g);
                            index = itr_g - groups.begin();
                        }
                    }
                }

                //combine input group with found group
                g.combine(friend_group);

                //remove found group from vector of groups
                groups.erase(groups.begin() + index);

                //remove initial group from vector of groups
                groups.erase(groups.end());

                //add new combined group to vector of groups
                groups.push_back(g);

                //return combined group
                return g;

            }   
        }

        x = (*itr).getXPos();
        y = (*itr).getYPos()-1;

        //check to ensure we are in bounds of 2D board vector
        if(x >= 0 && x < this->getDimension() && y >= 0 && y < this->getDimension()) {

            if(places[x][y] == color) {

                //get group of same colored piece
                //iterate through groups
                for(vector<group>::iterator itr_g = groups.begin(); itr_g != groups.end(); ++itr_g) {

                    //iterate through pieces in groups
                    for(vector<piece>::iterator itr_p = (*itr_g).pieces.begin(); itr_p != (*itr_g).pieces.end(); ++itr_p) {

                        //find friend again
                        if((*itr_p).getXPos() == x && (*itr_p).getYPos() == y) {
                            friend_group = (*itr_g);
                            index = itr_g - groups.begin();
                        }
                    }
                }

                //combine input group with found group
                g.combine(friend_group);

                //remove found group from vector of groups
                groups.erase(groups.begin() + index);

                //remove initial group from vector of groups (at the end since it is most recently added group)
                groups.erase(groups.end());

                //add new combined group to vector of groups
                groups.push_back(g);

                //return combined group
                return g;
            }
        }

    }

    return g;
}

int main() {

    //Basic fundtionality
    //Create board, players, and pieces
    //Basic loop where players are prompted to place pieces and board is drawn

    board b = board(9);
    player p1 = player(1);
    player p2 = player(2);
    piece p = piece();

    b.draw();

    bool p1_pass = false;
    bool p2_pass = false;
    bool valid_move = false;
    bool p1_turn = true;
    int turn_counter = 0;
    int x = -1;
    int y = -1;

    //game loops until both players pass
    while(!p1_pass && !p2_pass) {

        valid_move = false;

        //loop until a valid move is played
        while(!valid_move) {

            //trigger player whose turn it is to place a piece
            if(p1_turn) {
                cout << "Player 1 specify x position of your move. Enter -1 to pass your turn.\n";
                cin >> x;
                cout << "Player 1 specify y position of your move. Enter -1 to pass your turn.\n";
                cin >> y;

                //break loop if player passes
                if(x == -1 && y == -1) {
                    p1_pass = true;
                    break;
                }

                //Create piece based on player input
                p.setXPos(x);
                p.setYPos(y);
                p.setID(turn_counter);
                p.setColor(1);

            }
            else {
                cout << "Player 2 specify x position of your move. Enter -1 to pass your turn.\n";
                cin >> x;
                cout << "Player 2 specify y position of your move. Enter -1 to pass your turn.\n";
                cin >> y;

                //break loop if player passes
                if(x == -1 && y == -1) {
                    p2_pass = true;
                    break;
                }

                //Create piece based on player input
                p.setXPos(x);
                p.setYPos(y);
                p.setID(turn_counter);
                p.setColor(2);
            }

            valid_move = b.place(p);

        }

        //Create group for new piece
        group g = group();
        g.addPiece(p);
        b.addGroup(g);
 
        //Combine group with any adjacent existing groups
        g = b.findFriends(g);

        vector<group> capture_groups = b.getGroups();
        int liberties;
        //iterate through groups looking for captured group (liberties == 0)
        for(vector<group>::iterator itr = capture_groups.begin(); itr != capture_groups.end(); ++itr) {
            liberties = b.calcLiberties(*itr);
            if(liberties == 0) {
                //add captures to player's captures
                if(p1_turn)
                    p1.inc_captures((*itr).getPieces().size());
                else
                    p2.inc_captures((*itr).getPieces().size());

                //remove group from vector
                b.removeGroup(*itr);
            }
                
        }

        //Player turn change
        p1_turn = !p1_turn;

        //Draw board
        b.draw();

        //Increment counter
        turn_counter++;

    }

    return 0;

}