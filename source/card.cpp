/*
    Uno

    card.cpp
	created by breadone on 2023-01-10
*/

#include "card.hpp"
#include <time.h>

char Card::getColour() {
    return this->colour;
}

int Card::getNumber() {
    return this->number;
}

bool Card::stackable(Card &other) {

    // change colour or +4
    if (this->getNumber() >= 13) {
        return true; 
    }

    return ( (this->getColour() == other.getColour()) || (this->getNumber() == other.getNumber()) );
}