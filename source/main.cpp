/*
	Uno

	main.cpp
	created by breadone on 2023-01-10
*/

#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

#include "player.hpp"

#define TOP_SCREEN 0
#define BOTTOM_SCREEN 1
#define STARTING_CARDS 10

int main(int argc, char **argv) {

	// init graphics and fs
	NF_Set2D(TOP_SCREEN, 0);
	NF_Set2D(BOTTOM_SCREEN, 0);
	NF_SetRootFolder("NITROFS");

	// init sprite system
	NF_InitTiledBgBuffers();
	NF_InitTiledBgSys(TOP_SCREEN);
	NF_InitTiledBgSys(BOTTOM_SCREEN);

	// load top bg
	NF_LoadTiledBg("bg/top", "BG_TOP", 256, 256);
	NF_CreateTiledBg(TOP_SCREEN, 0, "BG_TOP");

	// load bottom bg
	NF_LoadTiledBg("bg/bottom", "BG_BOTTOM", 256, 256);
	NF_CreateTiledBg(BOTTOM_SCREEN, 0, "BG_BOTTOM");


	// make player and sprites
	Player *p1 = new Player(false, STARTING_CARDS);
	NF_LoadSpritePal(p1->getCard(0)->spritePath.c_str(), p1->getCard(0)->getColour()); // only need to load one pallete per card type
	
	for (int i = 0; i < STARTING_CARDS; i++) {

		Card *current = p1->getCard(i);
		u16 id = i+10;
		NF_LoadSpriteGfx(current->spritePath.c_str(), i, 16, 16);
		
		NF_CreateSprite(BOTTOM_SCREEN, i, id, id, (8*i), 120);
		oamUpdate(&oamSub);
	}

	while(1) {
		NF_SpriteOamSet(BOTTOM_SCREEN);
		swiWaitForVBlank();
		oamUpdate(&oamSub);
	}

	return 0;

}
