#include <string>
#include <iostream>

#include "games/slots/slotsInputChecks.h"

using namespace std;
int slotsInput(){
    int choice;
    do {
        cout << "Enter your 1, 2 or 3: ";
        cin >> choice;

        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please enter 1, 2 or 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
    } while (choice < 1 || choice > 3);

    return choice;
}

int slotsBetInput(int option1, int option2, int option3){
    int choice;
    do {
        cin >> choice;

        if (choice != option1 && choice != option2 && choice != option3) {
            cout << "Invalid choice. Please enter " << option1 << ", " << option2 << " or " << option3 << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
    } while (choice != option1 && choice != option2 && choice != option3);

    return choice;
}