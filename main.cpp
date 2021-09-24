#include "piece.h"
#include "group.h"
#include "board.h"
#include "player.h"
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {

    //Basic fundtionality
    //Create board, players, and pieces
    //Basic loop where players are prompted to place pieces and board is drawn

    player p1 = player(1);
    player p2 = player(2);
    piece p = piece();
    board b = board();
    int size = 9;

    cout << "What size board would you like to play on? (min: 5, max: 19)\n";
    cin >> size;
    cout << "\n";
    
    if(size < 5 || size > 19)
        b = board(9);
    else
        b = board(size);

    b.draw();

    bool p1_pass = false;
    bool p2_pass = false;
    bool valid_move = false;
    bool p1_turn = true;
    int turn_counter = 0;
    int x = -1;
    int y = -1;
    int row, col;
    int *scores;
    int p1_score, p2_score;

    //game loops until both players pass
    while(!p1_pass || !p2_pass) {

        valid_move = false;

        //loop until a valid move is played
        while(!valid_move) {

            //trigger player whose turn it is to place a piece
            if(p1_turn) {
                cout << "Player 1 specify x position of your move. Enter -1 to pass your turn.\n";
                cin >> x;
                cout << "Player 1 specify y position of your move. Enter -1 to pass your turn.\n";
                cin >> y;
                cout << "\n";

                //break loop if player passes
                if(x == -1 && y == -1) {
                    p1_pass = true;
                    break;
                }

                //convert x and y coordinates to row and col of 2d vector
                row = b.getDimension() - y;
                col = x - 1;

                //Create piece based on player input
                p.setXPos(row);
                p.setYPos(col);
                p.setID(turn_counter);
                p.setColor(1);

            }
            else {
                cout << "Player 2 specify x position of your move. Enter -1 to pass your turn.\n";
                cin >> x;
                cout << "Player 2 specify y position of your move. Enter -1 to pass your turn.\n";
                cin >> y;
                cout << "\n";

                //break loop if player passes
                if(x == -1 && y == -1) {
                    p2_pass = true;
                    break;
                }

                //convert x and y coordinates to row and col of 2d vector
                row = b.getDimension() - y;
                col = x - 1;

                //Create piece based on player input
                p.setXPos(row);
                p.setYPos(col);
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


    scores = b.evaluate();
    p1_score = scores[0];
    p2_score = scores[1];

    cout << "Player 1's score is " << p1_score << endl;
    cout << "Player 2's score is " << p2_score << endl;
    if(p1_score > p2_score) {
        cout << "Player 1 wins!\n";
    }
    else if (p1_score < p2_score) {
        cout << "Player 2 wins!\n";
    }
    else {
        cout << "It's a draw!\n";
    }
    return 0;

}