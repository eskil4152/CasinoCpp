#include "games/slots/slots.h"
#include "games/slots/slotsInputChecks.h"
#include "user/userdata.h"
#include "tools/checkInput.h"

#include <iostream>

using namespace std;
void slots(){
    cout << "Choose a slow machine: " << endl;
    cout << "1 - Cheap Slots Machine ($5 - $20 per spin)" << endl;
    cout << "2 - Expensive Slots Machine ($100 - $500 per spin)" << endl;
    cout << "3 - High Roller Slots Machine ($1000 - $5000 per spin)" << endl;

    int choice = slotsInput();

    switch (choice) {
    case 1:
        cheapSlots();
        break;
    case 2:
        expensiveSlots();
        break;
    case 3:
        highRollerSlots();
        break;
    default:
        break;
    }
}

void cheapSlots(){
    cout << "Hello" << endl;

    double* bet = new double;

    bool play = true;

    while (play) {
        cout << "How much would you like to use?" << endl;
        cout << "$5" << endl;
        cout << "$10" << endl;
        cout << "$20" << endl;
        *bet = (double)slotsBetInput(5, 10, 20);

        updateSpent(bet);

        // SPIN

        play = keepPlayingInput();
    }

    delete bet;
}

void expensiveSlots(){
    cout << "Welcome to the High Roller slots machine, valued customer!" << endl;
    cout << "How much would you like to use per spin?" << endl;

    cout << "$1000" << endl;
    cout << "$2000" << endl;
    cout << "$5000" << endl;

    int bet = slotsBetInput(1000, 2000, 5000);
}

void highRollerSlots(){
    cout << "Welcome to the expensive slots machine!" << endl;
    cout << "How much would you like to use per spin?" << endl;

    cout << "$100" << endl;
    cout << "$200" << endl;
    cout << "$500" << endl;

    int bet = slotsBetInput(100, 200, 500);
}