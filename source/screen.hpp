/*
	Uno

	screen.hpp
	created by breadone on 2023-01-12
*/

#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <nds.h>
#include <nf_lib.h>
#include <map>
#include <algorithm>
#include "card.hpp"

struct CardSprite {
    Card* card;
	int screen, x, y;
};

void drawCard(CardSprite);

#endif