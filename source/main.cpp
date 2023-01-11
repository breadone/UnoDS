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
#define STARTING_CARDS 7

typedef struct {
	int screen, x, y;
	int gfx, pal, vram;
} Sprite;

int main(int argc, char **argv) {

	// init graphics and fs
	NF_Set2D(TOP_SCREEN, 0);
	NF_Set2D(BOTTOM_SCREEN, 0);
	NF_SetRootFolder("NITROFS");

	// init sprite system
	NF_InitTiledBgBuffers();
	NF_InitTiledBgSys(TOP_SCREEN);
	NF_InitTiledBgSys(BOTTOM_SCREEN);
	NF_InitSpriteBuffers();
	NF_InitSpriteSys(BOTTOM_SCREEN);

	// load top bg
	NF_LoadTiledBg("bg/top", "BG_TOP", 256, 256);
	NF_CreateTiledBg(TOP_SCREEN, 0, "BG_TOP");

	// load bottom bg
	NF_LoadTiledBg("bg/bottom", "BG_BOTTOM", 256, 256);
	NF_CreateTiledBg(BOTTOM_SCREEN, 0, "BG_BOTTOM");


	// make player and sprites
	// Player *p1 = new Player(false, STARTING_CARDS);
	std::vector<Card> p1;
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		p1.push_back(Card());
	}

	// only need to load one palette per card colour
	NF_LoadSpritePal("card/0/0", MULTI);
	NF_LoadSpritePal("card/1/1", RED);
	NF_LoadSpritePal("card/2/1", BLUE);
	NF_LoadSpritePal("card/3/1", YELLOW);
	NF_LoadSpritePal("card/4/1", GREEN);
	NF_VramSpritePal(BOTTOM_SCREEN, MULTI, MULTI);
	NF_VramSpritePal(BOTTOM_SCREEN, RED, RED);
	NF_VramSpritePal(BOTTOM_SCREEN, BLUE, BLUE);
	NF_VramSpritePal(BOTTOM_SCREEN, YELLOW, YELLOW);
	NF_VramSpritePal(BOTTOM_SCREEN, GREEN, GREEN);

	for (int i = 0; i < STARTING_CARDS; i++) {
		Card current = p1[i];

		NF_LoadSpriteGfx(current.spritePath.c_str(), i, 32, 32);
		NF_VramSpriteGfx(BOTTOM_SCREEN, i, i, true);
		
		NF_CreateSprite(BOTTOM_SCREEN, i, i, current.getColour(), (32*i) + 3, 120);
	}

	while(1) {
		scanKeys();

		if (keysDown() & KEY_START) {
			exit(0);
		}

		NF_SpriteOamSet(BOTTOM_SCREEN);
		swiWaitForVBlank();
		oamUpdate(&oamSub);
	}

	return 0;

}
