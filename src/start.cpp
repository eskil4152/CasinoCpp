#include "start.h"
#include "entities/user.h"
#include "tools/name.h"
#include "tools/checkInput.h"
#include "actions/play.h"

#include <iostream>

using namespace std;
void start() {
    User user;
    user.setName(name());
    user.setMoney(1000);

    bool playing = true;

    while (playing) {
        int* choice = checkAction();
        switch (*choice){
        case 1:
            cout << "Chose 1, Play" << endl;;
            play();
            break;
        case 2:
            cout << "Chose 2, Check Money" << endl;;
            break;
        case 3:
            cout << "Chose 3, Check Record" << endl;;
            break;
        case 4:
            cout << "Hope you enjoyed your stay, goodbye!" << endl;;
            playing = false;
            break;
        default:
            break;
        }
        delete choice;
    }
}
