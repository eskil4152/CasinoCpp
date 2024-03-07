#include <iostream>

using namespace std;
int rouletteTableInput(){
    int choice;
    do {
        cout << "Enter your choice of table (Either 1 or 2): ";
        cin >> choice;

        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
        
    } while (choice != 1 && choice != 2);

    return choice;
}

int rouletteBetTypeInput(){
    int type;
    int min = 1;
    int max = 3;

    // NUMBER, COLOR, ODD/EVEN

    do {
        cout << "Enter type of bet" << endl;
        cout << "1 for a number" << endl;
        cout << "2 for red or black" << endl;
        cout << "3 for odd or even" << endl;

        cin >> type;
        if (type < min || type > max) {
            cout << "Invalid selection." << endl;
        }

    } while (type < min || type > max);
       
    return type;
}

int rouletteBetInput(int min, int max){
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