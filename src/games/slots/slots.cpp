#include "games/slots/slots.h"
#include "games/slots/slotsInputChecks.h"
#include "user/userdata.h"
#include "tools/checkInput.h"

#include <iostream>
#include <algorithm>
#include <random>

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

        bool win = spin(5);
    
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

    //int bet = slotsBetInput(1000, 2000, 5000);
}

void highRollerSlots(){
    cout << "Welcome to the expensive slots machine!" << endl;
    cout << "How much would you like to use per spin?" << endl;

    cout << "$100" << endl;
    cout << "$200" << endl;
    cout << "$500" << endl;

    //int bet = slotsBetInput(100, 200, 500);
}

bool spin(int symbolsNum){
    int rows = 3;
    int cols = 3;

    char* symbols = new char[symbolsNum];
    for (size_t i = 0; i < symbolsNum; i++){
        symbols[i] = 'A' + i;
    }

    char result[rows][cols];

    default_random_engine rng(time(NULL));
    shuffle(symbols, symbols + symbolsNum, default_random_engine(rng));

    int k = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            result[i][j] = symbols[k];
            k = (k + 1) % symbolsNum;
        }
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    if (result[1][0] == result[1][1] && result[1][1] == result[1][2]){
        cout << "You win!" << endl;
        return true;
    } else {
        cout << "You lose!" << endl;
        return false;
    }
}