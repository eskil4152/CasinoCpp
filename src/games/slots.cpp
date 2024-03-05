#include "games/slots.h"

#include <iostream>

using namespace std;
void slots(){
    cout << "Choose a slow machine: " << endl;
    cout << "1 - Cheap Slots Machine ($5 - $20 per spin)" << endl;
    cout << "2 - Expensive Slots Machine ($50 - $500 per spin)" << endl;
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

}

void expensiveSlots(){

}

void highRollerSlots(){

}

int slotsInput(){
    string slotsSelectionString;
    int result = 0;

    while (1){
        getline(cin, slotsSelectionString);

        bool isAllDigits = true;
        for (char c : slotsSelectionString){
            if (!isdigit(c)) {
                isAllDigits = false;
            }
        }
        
        if (isAllDigits && !slotsSelectionString.empty()) {
            result = stoi(slotsSelectionString);
            if (result >= 1 && result <= 3) {
                return result;
            } else {
                cout << "Please enter 1, 2 or 3" << endl;
            }
        } else {
            cout << "Please enter a valid number" << endl;
        }
    }
}