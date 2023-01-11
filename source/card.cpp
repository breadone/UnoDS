/*
    Uno

    card.cpp
	created by breadone on 2023-01-10
*/

#include "card.hpp"
#include <time.h>
#include <stdlib.h>


Card::Card() {
    // choose colour first
    this->colour = rand() % 4;

    // if the card colour is multi, assign it a random number
    if (this->colour != MULTI) {
        this->number = (rand() % 10) + 1;
    } else {
        this->number = (rand() % 1) + 1;
    }

    this->spritePath = "card/" + std::to_string(this->colour) + "/" + std::to_string(this->number);
    this->spriteID = this->colour + this->number;
}

Card::Card(int colour, int number) {
    this->colour = colour;
    this->number = number;

    this->spritePath = "card/" + std::to_string(this->colour) + "/" + std::to_string(this->number);
    this->spriteID = this->colour + this->number;
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