#include "start.h"
#include "entities/user.h"
#include "tools/checkInput.h"

#include "actions/play.h"
#include "actions/money.h"

#include "user/userdata.h"

#include <iostream>

using namespace std;
void start() {
    bool playing = true;

    while (playing) {
        int* choice = checkAction();

        switch (*choice){
        case 1:
            cout << "\r\n\r\n\r\n\r\n";
            play();
            break;
        case 2:
            cout << "\r\n\r\n\r\n\r\n";
            money();
            break;
        case 3:
            cout << "Chose 3, Check Record" << endl;
            break;
        case 4:
            cout << "Hope you enjoyed your stay, goodbye!" << endl;
            playing = false;
            break;
        default:
            break;
        }
        
        delete choice;
    }
}
