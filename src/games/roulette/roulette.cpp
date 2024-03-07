#include <iostream>

#include "games/roulette/roulette.h"
#include "games/roulette/rouletteInputs.h"
#include "games/roulette/rouletteBetTypes.h"

#include "user/userdata.h"

#include "tools/checkInput.h"

using namespace std;
void roulette(){
    cout << "Welcome to the roulette tables!" << endl;

    cout << "Which table will you sit at?" << endl;
    cout << "1 - Standard Table ($5 - $1.000)" << endl;
    cout << "2 - High Rollers Table ($1.000 - $10.000)" << endl;

    int choice = rouletteTableInput();

    switch (choice) {
    case 1:
        playRoulette(5, 1000);
        break;
    case 2:
        playRoulette(1000, 10000);
        break;
    default:
        break;
    }
}

int playRoulette(int min, int max){
    cout << "Hello, and welcome to roulette!" << endl;
    bool play = true;

    while (play){
        int type = rouletteBetTypeInput();
        Bet userBet;

        switch (type) {
        case 1:
            userBet.type = 1;
            userBet.number = numberBet();
            userBet.ratio = 36;
            break;
        case 2:
            userBet.type = 2;
            userBet.color = colorBet();
            userBet.ratio = 2;
            break;
        case 3:
            userBet.type = 3;
            userBet.oddEven = oddEvenBet();
            userBet.ratio = 2;
            break;
        default:
            break;
        }

        int bet = rouletteBetInput(min, max);
        double* money = getMoney();

        if (*money < bet){
            cout << "You are broke" << endl;
            return;
        }
        
        updateSpent(bet);
        changeMoney(-bet);

        if (spinWheel(userBet)){
            cout << "good" << endl;
        }

        play = keepPlayingInput();
    }   
}

bool spinWheel(Bet userBet){
    
}

struct Bet {
    int type;

    int number;
    string oddEven;
    string color;

    int ratio;
    int amount;
};
