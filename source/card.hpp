/*
    Uno

    card.hpp
	created by breadone on 2023-01-10
*/

class Card {
public:
    Card();
    Card(char colour, int number);

    char getColour();
    int getNumber();

    bool stackable(Card &other);

private:
    char colour;
    int number; // 1-9, 10=skip, 11=reverse, 12=+2, 13=+4, 14=change colour
};