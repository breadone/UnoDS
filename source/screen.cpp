/*
	Uno

	screen.cpp
	created by breadone on 2023-01-12
*/

#include "screen.hpp"
#include <vector>

struct CardSprite cardsprite;

// keeps track of what card gfx/sprites are in vram already, in order to stop duplicates
// one bool for each colour, and sprite id ig
std::vector<bool> palLoaded{true, true, true, true, true};

u8 isLoaded(int colour, int number) {
    u8 clrFound = false;
    u8 nFound = false;

    for (auto i: loaded) {
        if (i.card->getColour() == colour) {
            clrFound = 1;
        }

        if (i.card->getNumber() == number) {
            nFound = 10;
        }
    }

    return 

}

// draws card to screen
void drawCard(CardSprite c) {
	const int colour = c.card->getColour();
    const int number = c.card->getNumber();

	// check if each the gfx and pal are loaded
	u8 tmp = isLoaded(colour, number);

    // silly but convenient way to return two bools in an int
    bool palLoaded = tmp & 1;
	bool gfxLoaded = (tmp >> 1) & 1;

    // load sprite & pal into vram if not there
	if (!gfxLoaded) {
		NF_LoadSpriteGfx(c.card->spritePath.c_str(), colour, 32, 32);
		NF_VramSpriteGfx(c.screen, colour, colour, false); // keeps each colour in its corresponding vram slot for (hopefully) no collisions
        loaded.push_back(c);
	}

    if (!palLoaded) {
        NF_LoadSpritePal(c.card->spritePath.c_str(), colour);
        NF_VramSpritePal(c.screen, colour, colour);
    }

	NF_CreateSprite(c.screen, colour, colour, colour, c.x, c.y);
}

