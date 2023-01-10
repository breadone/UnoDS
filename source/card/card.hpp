/*
    Uno

    card.hpp
	created by breadone on 2023-01-10
*/
#include <string>

#define MULTI 0
#define RED 1
#define BLUE 2
#define YELLOW 3
#define GREEN 4

class Card {
public:
    Card();
    Card(int colour, int number);

    int getColour();
    int getNumber();

    bool stackable(Card &other);

private:
    int colour;
    int number; // 1-9, 10=skip, 11=reverse, 12=+2, 13=+4, 14=change colour
    std::string spritePath = "card/";
};