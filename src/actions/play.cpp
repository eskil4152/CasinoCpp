#include <iostream>

#include "actions/play.h"
#include "tools/checkInput.h"

#include "games/slots/slots.h"
#include "games/horses/horseRacing.h"
#include "games/blackjack/blackjack.h"
#include "games/roulette/roulette.h"
#include "games/poker/poker.h"

using namespace std;
void play(){
    cout << "What do you want to play? Here is our selection:" << endl;
    cout << "1: Slots\n" << "2: Horses\n" << "3: Blackjack\n" << "4: Poker\n" << "5: Roulette\n" << endl;

    int* gameSelectionPtr = gameTypeInput();
    int gameSelection = *gameSelectionPtr;
    delete gameSelectionPtr;

    switch (gameSelection) {
    case 1:
        slots();
        break;
    case 2:
        horseRacing();
        break;
    case 3:
        blackjack();
        break;
    case 4:
        poker();
        break;
    case 5:
        roulette();
        break;
    default:
        break;
    }
}