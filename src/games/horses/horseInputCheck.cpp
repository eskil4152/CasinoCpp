#include <string>
#include <iostream>
#include <limits>

using namespace std;
int horseSelectionInput(){
    int choice;
    do {
        cout << "Enter your horse of choice (between 1 and 12): ";
        cin >> choice;

        if (choice < 1 || choice > 12) {
            cout << "Invalid bet. Please enter a bet between 1 and 12" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice < 1 || choice > 12);
    
    return choice;
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
