#include <iostream>

#include "games/roulette/roulette.h"

using namespace std;
int numberBet(){
    int selection;
    int min = 0;
    int max = 36;

    // COLOR, NUMBER, ODD/EVEN

    do {
        cout << "Enter a number to bet on (0 - 36)" << endl;
    
        cin >> selection;
        if (selection < min || selection > max) {
            cout << "Invalid selection." << endl;
        }

    } while (selection < min || selection > max);
       
    return selection;
}

COLOR colorBet(){
    int selection;
    string selectionString;

    int min = 1;
    int max = 2;

    do {
        cout << "Do you want to bet on RED (1) or BLACK (2)?" << endl;
    
        cin >> selection;
        if (selection < min || selection > max) {
            cout << "Invalid selection." << endl;
        }

    } while (selection < min || selection > max);
       
    if (selection == 1){
        return RED;
    } else {
        return BLACK;
    }
}

ODD_EVEN oddEvenBet(){
    int selection;

    int min = 1;
    int max = 2;

    do {
        cout << "Do you want to bet on ODD (1) or EVEN (2)?" << endl;
    
        cin >> selection;
        if (selection < min || selection > max) {
            cout << "Invalid selection." << endl;
        }

    } while (selection < min || selection > max);
       
    if (selection == 1){
        return ODD;
    } else {
        return EVEN;
    }
}