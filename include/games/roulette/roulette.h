#ifndef ROULETTE_H
#define ROULETTE_H

#include "games/roulette/wheel.h"

struct Bet {
    int type;

    int number;
    ODD_EVEN oddEven;
    COLOR color;

    int ratio;
    int amount;
};

void roulette();
void playRoulette(int min, int max);
bool spinWheel(Bet userBet);

#endif