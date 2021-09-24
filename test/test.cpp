#define CONFIG_CATCH_MAIN
#include <catch2/catch_test_macros.hpp>
#include "group.h"
#include "board.h"


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

