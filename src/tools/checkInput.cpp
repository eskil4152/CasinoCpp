#include <string>
#include <iostream>

#include "tools/checkInput.h"

using namespace std;

int* checkAction(){
    cout << "What do you want to do now? \n";
    cout << "1: Play\n" << "2: Check Money\n" << "3: Check record\n" << "4: Leave\n";

    string s;
    int* res = new int;
    getline(cin, s);
    *res = stoi(s);
    return res;
}

int* gameTypeInput(){
    string gameSelectionString;
    int* result = new int;

    while (1)
    {
        getline(cin, gameSelectionString);

        bool isAllDigits = true;
        for (char c : gameSelectionString){
            if (!isdigit(c)) {
                isAllDigits = false;
            }
        }
        
        if (isAllDigits && !gameSelectionString.empty()) {
            *result = stoi(gameSelectionString);
            if (*result == (1 || 2 || 3)) {
                return result;
            } else {
                cout << "Please enter 1, 2 or 3\n";
            }
        } else {
            cout << "Please enter a valid number\n";
        }
    }
}