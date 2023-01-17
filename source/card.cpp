/*
    Uno

    card.cpp
	created by breadone on 2023-01-10
*/

#include "card.hpp"
#include <stdlib.h>
#include <chrono>
#include <random>


Card::Card() {
    // generate random number to determine card type
    int rnd = rand() % 1024 + 1;

    // 0.125 probability its a multi
    if ((int) rnd % 8) {
        this->colour = (rand() % 4) + 1;
    } else {
        this->colour = MULTI;
    }

    // if its multi, 0.33 probabilty its a +4, else change colour
    if (this->colour == MULTI) {
        this->number = (rand() % 3) ? 1 : 0;
    } else {
        this->number = (rand() % 10) + 1;
    }

    this->spritePath = "card/" + std::to_string(this->colour) + "/" + std::to_string(this->number);
    this->spriteID = (15*this->colour) + this->number;
}

Card::Card(int colour, int number) {
    this->colour = colour;
    this->number = number;

    this->spritePath = "card/" + std::to_string(this->colour) + "/" + std::to_string(this->number);
    this->spriteID = (15*this->colour) + this->number;
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