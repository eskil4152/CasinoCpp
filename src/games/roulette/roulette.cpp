#include <iostream>
#include <vector>

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
    }   
}

bool spinWheel(Bet userBet){
    int reds[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};

    WheelNumber wheel[37];

    WheelNumber zero;
    zero.color = GREEN;
    zero.number = 0;
    zero.oddEven = ZERO;
    wheel[0] = zero;

    for(int i = 1; i < 37; i++){
        WheelNumber number;
        number.number = i;
        number.oddEven = ODD;

        if (i % 2 == 0){
            number.oddEven = EVEN;
        }

        number.color = BLACK;
        for (int j = 0; j < 18; j++){
            if (reds[j] == i){
                number.color = RED;
            }
        }

        wheel[i] = number;
    }

    srand(time(NULL));

    WheelNumber randomNumber = wheel[rand() % 37];
    cout << "The winning number is " << randomNumber.number << " " << randomNumber.color << endl;

    switch (userBet.type){
    case 1:
        if (userBet.number == randomNumber.number){
            return true;
        } else {
            return false;
        }
        break;
    case 2:
        if (userBet.color == randomNumber.color){
            return true;
        } else {
            return false;
        }
        break;
    case 3:
        if (userBet.oddEven == randomNumber.oddEven){
            return true;
        } else {
            return false;
        }
        break;
    
    default:
    return false;
        break;
    }
}
