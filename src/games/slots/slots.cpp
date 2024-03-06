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
    bool play = true;

    while (play) {
        cout << "How much would you like to use?" << endl;
        cout << "$5" << endl;
        cout << "$10" << endl;
        cout << "$20" << endl;
        double bet = (double)slotsBetInput(5, 10, 20);

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

void expensiveSlots(){
    cout << "Welcome to the High Roller slots machine, valued customer!" << endl;
    bool play = true;

    while (play){
        cout << "How much would you like to use per spin?" << endl;

        cout << "$100" << endl;
        cout << "$200" << endl;
        cout << "$500" << endl;

        double bet = slotsBetInput(100, 200, 500);

        double* money = getMoney();
        if (*money < bet){
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

void highRollerSlots(){
    cout << "Welcome to the expensive slots machine!" << endl;
    bool play = true;

    while (play){
        cout << "How much would you like to use per spin?" << endl;
        cout << "$1000" << endl;
        cout << "$2000" << endl;
        cout << "$5000" << endl;

        double bet = slotsBetInput(1000, 2000, 5000);

        double* money = getMoney();
        if (*money < bet){
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
    }

    char result[rows][cols];

    srand(time(NULL));

    for (int i = 0; i < cols; i++){
        int random = rand() % symbolsNum;

        for (int j = 0; j < rows; j++){
            result[j][i] = symbols[random];
            if (random == 0) {
                result[0][i] = symbols[symbolsNum - 1];
                result[2][i] = symbols[random - 1];
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