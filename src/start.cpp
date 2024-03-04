#include "start.h"
#include "entities/user.h"
#include "tools/name.h"
#include "tools/checkInput.h"

#include <iostream>

#define MAX_NAME_SIZE 24

using namespace std;
void start() {
    User user;

    user.setName(name());
    user.setMoney(1000);

    cout << "\r\n\r\n";
    cout << "Hello, " << user.getName() << "! Welcome to the casino!\n";
    cout << "You currently have " << user.getMoney() << " money\n\n";
    
    cout << "What do you want to play? Here is our selection: \n";
    cout << "1: Cards\n" << "2: Horses\n" << "3: Slots\n";

    int* gameSelectionPtr = gameTypeInput();
    int gameSelection = *gameSelectionPtr;
    delete gameSelectionPtr;

    cout << "Game selection: " << gameSelection << "\n";
}
