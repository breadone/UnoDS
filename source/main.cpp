/*
	Uno

	main.cpp
	created by breadone on 2023-01-10
*/

#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>

#define TOP_SCREEN 0
#define BOTTOM_SCREEN 1

int main(int argc, char **argv) {

	// init graphics and fs
	NF_Set2D(TOP_SCREEN, 0);
	NF_Set2D(BOTTOM_SCREEN, 0);
	NF_SetRootFolder("NITROFS");

	// init sprite system
	NF_InitTiledBgBuffers();
	NF_InitTiledBgSys(TOP_SCREEN);
	NF_InitTiledBgSys(BOTTOM_SCREEN);

	while(1) {

		swiWaitForVBlank();

	}

	return 0;

}
