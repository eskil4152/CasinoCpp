#include "games/roulette/spinWheel.h"

#include <iostream>

using namespace std;
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