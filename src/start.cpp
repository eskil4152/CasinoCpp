#include "start.h"
#include "entities/user.h"
#include "tools/name.h"
#include "tools/checkInput.h"

#include <iostream>

using namespace std;
void start() {
    User user;
    user.setName(name());
    user.setMoney(1000);

    bool playing = true;

    while (playing) {
        int* choice = checkAction();
        //playing = res.keepPlaying;

        switch (*choice){
        case 1:
            cout << "Chose 1, Play\n";
            break;
        case 2:
            cout << "Chose 2, Check Money\n";
            break;
        case 3:
            cout << "Chose 3, Check Record\n";
            break;
        case 4:
            cout << "Hope you enjoyed your stay, goodbye!\n";
            playing = false;
            break;
        default:
            break;
        }
    }
    

    cout << "What do you want to play? Here is our selection: \n";
    cout << "1: Cards\n" << "2: Horses\n" << "3: Slots\n";

    int* gameSelectionPtr = gameTypeInput();
    int gameSelection = *gameSelectionPtr;
    delete gameSelectionPtr;

    switch (gameSelection) {
    case 1:
        cout << "Cards \n";
        break;
    
    case 2:
        cout << "Horses \n";
        break;
    case 3:
        cout << "Slots \n";
        break;
    default:
        break;
    }
}
