/*
    Uno

    card.hpp
	created by breadone on 2023-01-10
*/

#define RED 0
#define BLUE 1
#define YELLOW 2
#define GREEN 3
#define MULTI 4

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
};