#ifndef SPRITEMANAGER_HPP
#define SPRITEMANAGER_HPP

#include <nf_lib.h>
#include <vector>
#include <algorithm>
#include "card.hpp"

#pragma once
class SpriteManager {
public:
    static void init();

    static void drawPlayerCards(std::vector<Card> deck);
private:
    inline static std::vector<int> drawnSprites;
    inline static int overflowTOS;
};


#endif