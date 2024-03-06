#include <string>
#include <iostream>

using namespace std;
int horseSelectionInput(){
    string horseSelectionString;

    while (1){
        getline(cin, horseSelectionString);

        bool isAllDigits = true;
        for (char c : horseSelectionString){
            if (!isdigit(c)) {
                isAllDigits = false;
            }
        }
        
        if (isAllDigits && !horseSelectionString.empty()) {
            int result = stoi(horseSelectionString);
            if (result >= 1 && result <= 12) {
                return result;
            } else {
                cout << "Please enter a number between 1 and 12" << endl;
            }
        } else {
            cout << "Please enter a valid number" << endl;
        }
    }
}

int betInput(){
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
            return stoi(betString);
        } else {
            cout << "Please enter a valid number" << endl;
        }
    }
}