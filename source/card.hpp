/*
    Uno

    card.hpp
	created by breadone on 2023-01-10
*/
#include <string>

#ifndef CARD_HPP
#define CARD_HPP

#define MULTI 0
#define RED 1
#define BLUE 2
#define YELLOW 3
#define GREEN 4

class Card {
public:
    std::string spritePath;
    int spriteID;

    Card();
    Card(int colour, int number);

    int getColour();
    int getNumber();

    bool stackable(Card &other);

private:
    int colour;
     // 1-9, 10=+2, 11=reverse, 12=reverse
     // if its a multicolour, 0=change colour, 1=+4
    int number;
};

#endif