#include <iostream>
#include <vector>

#include "games/roulette/roulette.h"
#include "games/roulette/rouletteInputs.h"
#include "games/roulette/rouletteBetTypes.h"
#include "games/roulette/spinWheel.h"

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

void playRoulette(int min, int max){
    cout << "Hello, and welcome to roulette!" << endl;
    bool play = true;

    while (play){
        int type = rouletteBetTypeInput();
        Bet userBet;

        switch (type) {
        case 1:
            userBet.type = 1;
            userBet.number = numberBet();
            userBet.ratio = 35;
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

        bool result = spinWheel(userBet);

        if (result){
            int won = bet * userBet.ratio;
            cout << "Congratiolations, you won $" << won << "!" << endl;

            updateEarned(won);
            changeMoney(won);
        }
        
        cout << "You lose.." << endl;

        play = keepPlayingInput();
        
        delete money;
    }   
}
