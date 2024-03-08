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
    int bet;
    
    do {
        cout << "Enter your bet: ";
        cin >> bet;

        if (bet < 1 || bet > 100000) {
            cout << "Invalid bet, try again (Max 100k)" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (bet < 1 || bet > 100000);
    
    return bet;
}
