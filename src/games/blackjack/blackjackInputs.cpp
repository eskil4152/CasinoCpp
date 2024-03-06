#include "games/blackjack/blackjackInputs.h"

#include <iostream>

using namespace std;
int blackjackBetInput(int min, int max){
    int bet;
    do {
        cout << "Enter your bet (between " << min << " and " << max << "): ";
        cin >> bet;

        if (bet < min || bet > max) {
            cout << "Invalid bet. Please enter a bet between " << min << " and " << max << ".\n";
        }
    } while (bet < min || bet > max);

    return bet;
}

int blackjackTableInput(){
    return 1;
}