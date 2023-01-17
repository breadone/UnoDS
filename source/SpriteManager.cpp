#include "SpriteManager.hpp"

// int SpriteManager::overflowTOS = 2;

void SpriteManager::drawPlayerCards(std::vector<Card> deck) {
    int x = 0; // x pos of cards
    for (Card c : deck) {
        int newSpriteID = c.spriteID;

        if (std::find(SpriteManager::drawnSprites.begin(), SpriteManager::drawnSprites.end(), newSpriteID) != SpriteManager::drawnSprites.end()) {
            newSpriteID = overflowTOS++;
        }

        SpriteManager::drawnSprites.push_back(newSpriteID);

        NF_CreateSprite(1, newSpriteID, c.spriteID, c.getColour(), 16+x*32, 130);
        x++;
    }
}

void SpriteManager::init() {
    SpriteManager::drawnSprites.clear();
    SpriteManager::overflowTOS = 2;
}