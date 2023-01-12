/*
	Uno

	screen.cpp
	created by breadone on 2023-01-12
*/

#include "screen.hpp"
#include <vector>

struct CardSprite cardsprite;

// keeps track of what card gfx/sprites are in vram already, in order to stop duplicates
std::vector<CardSprite> loaded;

bool isPalLoaded(int colour) {
    for (auto i: loaded) {
        if (i.card->getColour() == colour) {
            return true;
        }
    }
    return false;
}

bool isGFXLoaded(int colour, int number) {
    if (!isPalLoaded(colour))
        return false;

    for (auto i: loaded) {
        if (i.card->getColour() == colour && i.card->getNumber() == number) {
            return true;
        }
    }
    return false;
}

// draws card to screen
void drawCard(CardSprite c) {
	const int colour = c.card->getColour();
    const int number = c.card->getNumber();
	bool palLoaded;
	bool gfxLoaded;

	// check if each the gfx and pal are loaded
	palLoaded = isPalLoaded(colour);
    gfxLoaded = isGFXLoaded(colour, number);

    if (!palLoaded) {
        NF_LoadSpritePal(c.card->spritePath.c_str(), colour);
        NF_VramSpritePal(c.screen, colour, colour);
    }

	// load sprite & pal into vram if not there
	if (!gfxLoaded) {
		NF_LoadSpriteGfx(c.card->spritePath.c_str(), colour, 32, 32);
		NF_VramSpriteGfx(c.screen, colour, colour, false); // keeps each colour in its corresponding vram slot for (hopefully) no collisions
        loaded.push_back(c);
	}

	NF_CreateSprite(c.screen, colour, colour, colour, c.x, c.y);
}

