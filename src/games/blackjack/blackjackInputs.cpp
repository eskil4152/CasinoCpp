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
    int choice;
    do {
        cout << "Enter your choice of table (between 1 and 3): ";
        cin >> choice;

        if (choice < 1 || choice > 3) {
            cout << "Invalid bet. Please enter a bet between 1 and 3.\n";
        }
    } while (choice < 1 || choice > 3);

    return choice;
}

bool blackjackHit(){
    char choice;

    do {
        cout << "Do you want to hit (h) or stand (s)" << endl;
        cin >> choice;
        cin.clear();

        if (choice != 'h' && choice != 'n') {
            cout << "Invalid bet. Please enter a bet between 1 and 3.\n";
        }
    } while (choice != 'h' && choice != 's');

    if (choice == 'h'){
        return true;
    }

    return false;
}