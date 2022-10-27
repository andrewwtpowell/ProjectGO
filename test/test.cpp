#define CONFIG_CATCH_MAIN
#include <catch2/catch_test_macros.hpp>
#include "/home/apowell/projects/ProjectGO/include/group.h"
#include "/home/apowell/projects/ProjectGO/include/board.h"


// Test Group functions

// Test Combine function
TEST_CASE("Groups can be combined","[group]") {

    //create groups to combine
    group group1 = group();
    group group2 = group();

    //create pieces to be part of groups
    piece piece1 = piece(1,1,1,1);
    piece piece2 = piece(1,2,2,1);
    piece piece3 = piece(1,3,3,1);
    piece piece4 = piece(2,2,4,1);
    piece piece5 = piece(2,3,5,1);
    piece piece6 = piece(2,5,6,1);

    SECTION ("Groups of equal size can be combined") {

        group1.addPiece(piece1);
        group1.addPiece(piece3);
        group1.addPiece(piece5);

        group2.addPiece(piece2);
        group2.addPiece(piece4);
        group2.addPiece(piece6);

        group1.combine(group2);

        REQUIRE(group1.pieces.size() == 6);
        REQUIRE(group2.pieces.size() == 3);

    }

    SECTION ("Groups of unequal size can be combined") {

        group1.addPiece(piece1);
        group1.addPiece(piece3);
        group1.addPiece(piece5);

        group2.addPiece(piece2);
        group2.addPiece(piece4);

        group1.combine(group2);

        REQUIRE(group1.pieces.size() == 5);
        REQUIRE(group2.pieces.size() == 2);

    }

    SECTION ("Combining an empty group does not cause errors") {

        group1.addPiece(piece1);
        group1.addPiece(piece3);
        group1.addPiece(piece5);

        group1.combine(group2);

        REQUIRE(group1.pieces.size() == 3);
        
    }
}


//Test Board functions

//Test place function
TEST_CASE("Pieces can be placed within the grid","[board]") {

    //Setup
    //Create a board of size 9x9
    board test_board = board();
    
    //Create pieces
    piece w_piece1 = piece(1,1,1,1);
    piece w_piece2 = piece(1,2,2,1);
    piece w_piece3 = piece(1,3,3,1);
    piece w_piece4 = piece(2,2,4,1);
    piece w_piece5 = piece(2,3,5,1);
    piece w_piece6 = piece(2,5,6,1);

    piece b_piece1 = piece(8,9,7,2);
    piece b_piece2 = piece(7,9,8,2);
    piece b_piece3 = piece(5,4,9,2);
    piece b_piece4 = piece(6,9,10,2);
    piece b_piece5 = piece(8,6,11,2);
    piece b_piece6 = piece(8,7,12,2);

    //piece for occupied spot testing
    piece copy_w_piece1 = piece(1,1,100,1);

    //pieces for out of bounds testing
    piece oob_piece1 = piece(2,10,101,1);
    piece oob_piece2 = piece(0,9,102,1);
    piece oob_piece3 = piece(10,9,103,1);
    piece oob_piece4 = piece(9,0,104,1);

    //pieces for a side capture
    piece side_cap_w1 = piece(1,7,201,1);
    piece side_cap_w2 = piece(1,9,202,1);
    piece side_cap_w3 = piece(2,8,203,1);
    piece side_cap_b = piece(1,8,204,2);

    //pieces for a corner capture
    piece corner_cap_b1 = piece(8,1,300,2);
    piece corner_cap_b2 = piece(9,2,301,2);
    piece corner_cap_w = piece(9,1,302,1);

    //pieces for a regular capture
    piece cap_w1 = piece(3,7,400,1);
    piece cap_w2 = piece(4,6,401,1);
    piece cap_w3 = piece(5,7,402,1);
    piece cap_w4 = piece(4,8,403,1);
    piece cap_b = piece(4,7,404,2);

    //Test placing pieces in open spots
    SECTION("Pieces can be placed") {
        test_board.place(w_piece1);
        test_board.place(w_piece2);
        test_board.place(w_piece3);
        test_board.place(w_piece4);
        test_board.place(w_piece5);
        test_board.place(w_piece6);

        REQUIRE(test_board.getPiecesPlaced() == 6);
    }

    //Test placing pieces in occupied spots
    SECTION("Pieces cannot be placed in occupied locations") {
        test_board.place(w_piece1);
        test_board.place(copy_w_piece1);

        REQUIRE(test_board.getPiecesPlaced() == 1);
    }

    //Test placing pieces outside of the bounds of the board
    SECTION("Pieces cannot be placed outside of the bounds of the board") {
        test_board.place(oob_piece1);
        test_board.place(oob_piece2);
        test_board.place(oob_piece3);
        test_board.place(oob_piece4);

        REQUIRE(test_board.getPiecesPlaced() == 0);
    }

    //Test placing pieces where they would automatically be captured (surrounded by other pieces on all 4 liberties)
    SECTION("Pieces cannot be placed where they would immediately be captured") {
        test_board.place(cap_w1);
        test_board.place(cap_w2);
        test_board.place(cap_w3);
        test_board.place(cap_w4);
        test_board.place(cap_b);

        REQUIRE(test_board.getPiecesPlaced() == 4)
    }

    //Test placing pieces where they would automatically be captured (surrounded by other pieces and a side of the board)
    SECTION("Pieces cannot be placed where they would immediately be captured") {
        test_board.place(side_cap_w1);
        test_board.place(side_cap_w2);
        test_board.place(side_cap_w3);
        test_board.place(side_cap_b);

        REQUIRE(test_board.getPiecesPlaced() == 3)
    }
    
    //Test placing pieces where they would automatically be captured (surrounded by other pieces and 2 sides of the board)
    SECTION("Pieces cannot be placed where they would immediately be captured") {
        test_board.place(corner_cap_b1);
        test_board.place(corner_cap_b2);
        test_board.place(corner_cap_w);

        REQUIRE(test_board.getPiecesPlaced() == 2)
    }
}

//Test evaluate function

//Test findSurrounding function

//Test calcLiberties function

//Test removeGroup function

//Test findFriends function