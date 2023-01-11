/*
    Uno

    player.hpp
	created by breadone on 2023-01-11
*/

#include "card.hpp"
#include <vector>
#include <stdlib.h>
#include <time.h>

class Player {
public:
    bool isBot;

    Player(bool bot, int startingCards);

    void pickupCard();
    Card* playRandom();
    Card* play(Card &card);
    Card* getCard(int index);

private:
    std::vector<Card*> cards;

};