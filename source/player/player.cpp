/*
    Uno

    player.cpp
	created by breadone on 2023-01-11
*/

#include "player.hpp"
    
Player::Player(bool bot, int startingCards) {
    this->isBot = bot;

    // adds random starting cards
    for (int i = 0; i < startingCards; i++) {
        Card *c = new Card();
        this->cards.push_back(c);
    }
}

void Player::pickupCard() {
    Card *c = new Card();
    this->cards.push_back(c);
}

Card Player::playRandom() {
    // random seed
    srand(time(0));
    int index = rand() % this->cards.size();

    Card *toPlay = this->cards[index];
    this->cards.erase(cards.begin()+index);
}

Card Player::play(Card &card) {

}