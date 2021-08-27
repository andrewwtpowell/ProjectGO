#include "group.h"

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