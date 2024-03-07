#include "games/slots/slots.h"
#include "games/slots/slotsInputChecks.h"
#include "user/userdata.h"
#include "tools/checkInput.h"

#include <iostream>
#include <algorithm>
#include <random>
#include <unistd.h>

using namespace std;
void slots(){
    cout << "Choose a slot machine: " << endl;
    cout << "1 - Cheap Slots Machine ($5 - $20 per spin)" << endl;
    cout << "2 - Expensive Slots Machine ($100 - $500 per spin)" << endl;
    cout << "3 - High Roller Slots Machine ($1000 - $5000 per spin)" << endl;

    int choice = slotsInput();

    switch (choice) {
    case 1:
        slotsMachine(1, 5, 10, 20);
        break;
    case 2:
        slotsMachine(2, 100, 200, 500);
        break;
    case 3:
        slotsMachine(3, 1000, 2000, 5000);
        break;
    default:
        break;
    }
}

void slotsMachine(int choice, int min, int mid, int max){
    switch (choice){
    case 1:
        cout << "Hello" << endl;
        break;
    case 2:
        cout << "Hello, and welcome." << endl;
        break;
    case 3:
        cout << "Hello, valued customer! Please enjoy out state of the art slot machines!" << endl;
        break;
    default:
        break;
    }

    bool play = true;

    while (play) {
        cout << "How much would you like to use?" << endl;
        cout << "$" << min << endl;
        cout << "$" << mid << endl;
        cout << "$" << max << endl;
        double bet = (double)slotsBetInput(min, mid, max);

        double* money = getMoney();
        if (*money < bet)
        {
            cout << "You are broke" << endl;
            sleep(1);
            return;
        }
        
        updateSpent(bet);
        changeMoney(-bet);

        if (spin(5)){
            updateEarned(bet * 5);
            changeMoney(bet * 5);
        }
    
        play = keepPlayingInput();
    }
}

bool spin(int symbolsNum){
    int rows = 3;
    int cols = 3;

    char* symbols = new char[symbolsNum];
    for (int i = 0; i < symbolsNum; i++){
        symbols[i] = 'A' + i;
        cout << "Symbols: " << symbols[i] << endl;
    }

    char result[rows][cols];

    srand(time(NULL));

    for (int i = 0; i < cols; i++){
        int random = rand() % symbolsNum;
        cout << "Random is " << random << endl;

        for (int j = 0; j < rows; j++){
            result[j][i] = symbols[random];
            if (random == 0) {
                result[0][i] = symbols[symbolsNum - 1];
                result[2][i] = symbols[random + 1];
            } else if (random == symbolsNum - 1) {
                result[0][i] = symbols[random - 1];
                result[2][i] = symbols[0];
            } else {
                result[0][i] = symbols[random - 1];
                result[2][i] = symbols[random + 1];
            }
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