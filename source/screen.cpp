/*
	Uno

	screen.cpp
	created by breadone on 2023-01-12
*/

#include <nds.h>
#include <nf_lib.h>
#include <map>
#include <vector>
#include <algorithm>
#include "card.cpp"

typedef struct {
	Card* card;
	int screen, x, y;
} CardSprite;

// keeps track of what card gfx/sprites are in vram already, in order to stop duplicates
std::map<u8, std::vector<u8>> vram{};

// draws card to screen
void drawCard(CardSprite c) {
	const int colour = c.card->getColour();
	bool palLoaded = false;
	bool gfxLoaded = false;

	// check if each the gfx and pal are loaded
	palLoaded = vram.count(colour);
	// if the pal isnt loaded then the gfx definitely wont be, so avoid that crash
	if (palLoaded) {
        std::vector<u8> vramGFX = vram[colour];
		gfxLoaded = std::count(vramGFX.begin(), vramGFX.end(), c.card->getNumber());
	}

    if (!palLoaded) {
        NF_LoadSpritePal(c.card->spritePath.c_str(), colour);
		NF_VramSpritePal(c.screen, colour, colour);

        std::vector<u8> vramGFX{};
        vram[colour] = vramGFX;
    }

	// load sprite & pal into vram if not there
	if (!gfxLoaded) {
		NF_LoadSpriteGfx(c.card->spritePath.c_str(), colour, 32, 32);
		NF_VramSpriteGfx(c.screen, colour, colour, false); // keeps each colour in its corresponding vram slot for (hopefully) no collisions
        gfxLoaded = true;
	}



	NF_CreateSprite(c.screen, colour, colour, colour, c.x, c.y);
}

void unDrawCard(CardSprite c) {
	
}