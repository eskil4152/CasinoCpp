#include <string>
#include <iostream>

#include "tools/checkInput.h"

using namespace std;
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
            return result;
        } else {
            cout << "Please enter a valid number\n";
        }
    }
}