#include <iostream>

#include "actions/play.h"
#include "tools/checkInput.h"

#include "games/slots/slots.h"

using namespace std;
void play(){
    cout.clear();
    cout << "What do you want to play? Here is our selection:" << endl;
    cout << "1: Cards\n" << "2: Horses\n" << "3: Slots" << endl;

    int* gameSelectionPtr = gameTypeInput();
    int gameSelection = *gameSelectionPtr;
    delete gameSelectionPtr;

    switch (gameSelection) {
    case 1:
        cout << "Cards" << endl;;
        break;
    case 2:
        cout << "Horses" << endl;;
        break;
    case 3:
        slots();
        break;
    default:
        break;
    }
}