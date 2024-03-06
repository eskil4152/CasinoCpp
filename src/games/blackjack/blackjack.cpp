#include <iostream>

#include "games/blackjack/blackjack.h"
#include "games/blackjack/blackjackInputs.h"
#include "games/blackjack/blackjackResult.h"
#include "games/blackjack/blackjackDeal.h"
#include "user/userdata.h"
#include "tools/checkInput.h"

using namespace std;
void blackjack(){
    cout << "Welcome to blackjack! What table will you sit at?" << endl;

    cout << "1 - Cheap Table ($5 - $50)" << endl;
    cout << "2 - Expensive Table ($100 - $500)" << endl;
    cout << "3 - High Rollers Table ($1000 - $5000)" << endl;

    int choice = blackjackTableInput();

    switch (choice) {
    case 1:
        cheapBlackjackTable();
        break;
    case 2:
        //expensiveSlots();
        break;
    case 3:
        //highRollerSlots();
        break;
    default:
        break;
    }
}

void cheapBlackjackTable(){
    cout << "Hello" << endl;
    bool play = true;

    while (play) {
        cout << "How much would you like to bet?" << endl;
        int bet = blackjackBetInput(5, 50);
        cout << "1";

        double* money = getMoney();
        cout << "2";
        if (*money < bet)
        {
            cout << "You are broke" << endl;
            return;
        }
        cout << "3";
        
        updateSpent(bet);
        cout << "4";
        changeMoney(-bet);
        cout << "5";

        BlackjackResult result = deal();
        cout << "6";

        if (result.won){
            if (result.blackjack){
                updateEarned(bet*2.5);
                changeMoney(bet*2.5);
            } else {
                updateEarned(bet*2);
                changeMoney(bet*2);
            }
        }
    
        play = keepPlayingInput();
    }
}