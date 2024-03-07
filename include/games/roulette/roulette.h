#ifndef ROULETTE_H
#define ROULETTE_H

enum COLOR {
    RED, BLACK, GREEN
};

enum ODD_EVEN {
    ODD, EVEN, ZERO
};

struct WheelNumber {
    int number;
    COLOR color;
    ODD_EVEN oddEven;
};

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