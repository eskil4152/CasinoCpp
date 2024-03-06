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

        spin();

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

void spin() {
    int rows = 3;
    int cols = 3;
    int symbolsNum = 5;

    char symbols[] = {'A', 'B', 'C', 'D', 'E'};
    char result[rows][cols];

    srand(time(NULL));

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            int randomIndex = rand() % symbolsNum;
            result[i][j] = symbols[randomIndex];
        }
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%c ", result[i][j]);
        }
        printf("\n");
    }

    if (result[1][0] == result[1][1] && result[1][1] == result[1][2])
    {
        cout << "You win!" << endl;
    } else {
        cout << "You lose!" << endl;
    }
}