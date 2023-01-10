/*
    Uno

    card.cpp
	created by breadone on 2023-01-10
*/

#include "card.hpp"
#include <time.h>
#include <stdlib.h>
#include "alg.cpp"

Card::Card() {
    // seed for rand
    srand(time(0));

    this->number = (rand() % 14) + 1;

    // if the card number is a +4 or change colour, assign it a random one
    if (this->number >= 13) {
        this->colour = MULTI;
    } else {
        this->colour = (rand() % 4);
    }
}

Card::Card(int colour, int number) {
    this->colour = colour;
    this->number = allowableRange(number, 1, 14);
}

int Card::getColour() {
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