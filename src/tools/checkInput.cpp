#include <string>
#include <iostream>

#include "tools/checkInput.h"

using namespace std;

// TODO fix
int* checkAction(){
    cout << "What do you want to do now?" << endl;;
    cout << "1: Play" << endl; 
    cout << "2: Check Money" << endl;
    cout << "3: Check record" << endl; 
    cout << "4: Leave" << endl;

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
            if (*result >= 1 && *result <= 4) {
                return result;
            } else {
                cout << "Please enter 1, 2, 3 or 4" << endl;;
            }
        } else {
            cout << "Please enter a valid number" << endl;;
        }
    }
}

string* nameInput(){
    string* name = new string;
    cout << "What is your name?" << endl;

    while(1){
        string temp = NULL;
        getline(cin, temp);

        if (temp.empty()) {
            cout << "Enter a valid string" << endl;
        } else {
            *name = temp;
            return name;
        }
    }
}