/*
	Uno

	main.cpp
	created by breadone on 2023-01-10
*/

#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>


int main(int argc, char **argv) {

	consoleDemoInit();		
	consoleClear();			
	setBrightness(3, 0);	

	iprintf("\n Hello World!");

	while(1) {

		swiWaitForVBlank();

	}

	return 0;

}
