#include <string>
#include <iostream>

#include "games/slots/slotsInputChecks.h"

using namespace std;
int slotsInput(){
    string slotsSelectionString;

    while (1){
        getline(cin, slotsSelectionString);

        bool isAllDigits = true;
        for (char c : slotsSelectionString){
            if (!isdigit(c)) {
                isAllDigits = false;
            }
        }
        
        if (isAllDigits && !slotsSelectionString.empty()) {
            int result = stoi(slotsSelectionString);
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

int slotsBetInput(int option1, int option2, int option3){
    string betString;
    int result = 0;

    while (1){
        getline(cin, betString);

        bool isAllDigits = true;
        for (char c : betString){
            if (!isdigit(c)) {
                isAllDigits = false;
            }
        }
        
        if (isAllDigits && !betString.empty()) {
            result = stoi(betString);
            if (result == option1 || result == option2 || result == option3) {
                return result;
            } else {
                cout << "Please enter " << option1 << ", " << option2 << " or " << option3 << endl;
            }
        } else {
            cout << "Please enter a valid number" << endl;
        }
    }
}