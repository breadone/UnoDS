/*
	Uno

	main.cpp
	created by breadone on 2023-01-10
*/

#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <map>
#include <vector>
#include <time.h>
#include <sstream>

// #include "player.hpp"
#include "card.hpp"

#define TOP_SCREEN 0
#define BOTTOM_SCREEN 1
#define STARTING_CARDS 7

// start addresses
#define MULTI_START 0 // 0
#define RED_START 15
#define BLUE_START 30
#define YELLOW_START 45
#define GREEN_START 60 // 4

void loadCardSprites() {
	// load sprites
	for (int col = RED; col <= GREEN; col++) {
		for (int card = 1; card <= 10; card++) {
			std::stringstream ss;
			ss << "card/" << col << "/" << card; // mfw no string interpolation

			u16 id = 15*col + card;
			NF_LoadSpriteGfx(ss.str().c_str(), id, 32, 32);
			NF_VramSpriteGfx(BOTTOM_SCREEN, id, id, false);
			iprintf("Loaded sprite %d\n", card);
		}
	}

	// load pal
	NF_LoadSpritePal("card/0/1", MULTI);
	NF_LoadSpritePal("card/1/1", RED);
	NF_LoadSpritePal("card/2/1", BLUE);
	NF_LoadSpritePal("card/3/1", YELLOW);
	NF_LoadSpritePal("card/4/1", GREEN);
	NF_VramSpritePal(BOTTOM_SCREEN, MULTI, MULTI);
	NF_VramSpritePal(BOTTOM_SCREEN, RED, RED);
	NF_VramSpritePal(BOTTOM_SCREEN, BLUE, BLUE);
	NF_VramSpritePal(BOTTOM_SCREEN, YELLOW, YELLOW);
	NF_VramSpritePal(BOTTOM_SCREEN, GREEN, GREEN);
}

int main(int argc, char **argv) {
	// init fs
	NF_SetRootFolder("NITROFS");

	// init sprite system
	NF_Set2D(TOP_SCREEN, 0);
	NF_Set2D(BOTTOM_SCREEN, 0);

	NF_InitTiledBgBuffers();
	NF_InitTiledBgSys(TOP_SCREEN);
	NF_InitTiledBgSys(BOTTOM_SCREEN);
	NF_InitSpriteBuffers();
	NF_InitSpriteSys(BOTTOM_SCREEN);

	// load bottom bg
	NF_LoadTiledBg("bg/bottom", "BG_BOTTOM", 512, 256);
	NF_CreateTiledBg(BOTTOM_SCREEN, 0, "BG_BOTTOM");

	// show loading screen
	NF_LoadTiledBg("bg/loading", "BG_LOAD", 256, 256);
	NF_CreateTiledBg(TOP_SCREEN, 0, "BG_LOAD");

	// load data
	loadCardSprites();

	// load real top bg
	NF_LoadTiledBg("bg/top", "BG_TOP", 256, 256);
	NF_CreateTiledBg(TOP_SCREEN, 0, "BG_TOP");


	// make player and sprites
	srand(time(NULL));
	// Player *p1 = new Player(false, STARTING_CARDS);
	std::vector<Card> p1;

	for (int i = 0; i < STARTING_CARDS; i++)
		p1.push_back(Card());

	for (int i = 0; i < STARTING_CARDS; i++) {
		// Card* current = p1->getCard(i);
		Card current = p1[i];
		
		u16 id = 15*current.getColour() + current.getNumber();

		// drawCard(c);
		NF_CreateSprite(BOTTOM_SCREEN, id, id, current.getColour(), 32*i, 130);
	}

	while(1) {
		scanKeys();

		// exit key
		if (keysDown() & KEY_START) { exit(0); }

		NF_SpriteOamSet(BOTTOM_SCREEN);
		swiWaitForVBlank();
		oamUpdate(&oamSub);
	}

	return 0;

}
