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
        playBlackjack(1, 5, 50);
        break;
    case 2:
        playBlackjack(2, 100, 500);
        break;
    case 3:
        playBlackjack(3, 1000, 5000);
        break;
    default:
        break;
    }
}

void playBlackjack(int rank, int min, int max){
    switch (rank){
    case 1:
        cout << "Hello" << endl;
        break;
    case 2:
        cout << "Hello and welcome to blackjack" << endl;
        break;
    case 3:
        cout << "Hello, valued customer! Welcome to blackjack!" << endl;
        break;
    
    default:
        break;
    }
    bool play = true;

    while (play) {
        cout << "How much would you like to bet?" << endl;
        int bet = blackjackBetInput(min, max);

        double* money = getMoney();
        if (*money < bet){
            cout << "You are broke" << endl;
            return;
        }
        
        updateSpent(bet);
        changeMoney(-bet);

        BlackjackResult result = deal();

        if (result == BLACKJACK){
            updateEarned(bet*2.5);
            changeMoney(bet*2.5);
        } else if (result == WIN) {
            updateEarned(bet*2);
            changeMoney(bet*2);
        } else if (result == PUSH) {
            updateEarned(bet*1);
            changeMoney(bet*1);
        }
    
        play = keepPlayingInput();
    }
}