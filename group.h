#pragma once
#include "piece.h"
#include <utility>
#include <vector>

class group {

    private:

        

    public:

        std::vector<piece> pieces;

        group();

        std::vector<piece> getPieces() { return pieces; }
        void addPiece(piece p) { pieces.push_back(p); }
        void combine(group g);

        bool operator== (const group &other) const;
        bool operator!= (const group &other) const;

};