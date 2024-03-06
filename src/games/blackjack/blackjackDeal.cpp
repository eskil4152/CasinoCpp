#include "games/blackjack/blackjackResult.h"
#include "games/blackjack/blackjackDeal.h"
#include "games/blackjack/blackjackDeck.h"

#include <iostream>

using namespace std;
BlackjackResult deal(){
    BlackjackDeck deck;
    BlackjackResult result;

    deck.shuffle();

    card dealerCards[2];
    card playerCards[2];

    playerCards[0] = deck.drawCard();
    cout << "You drew a " << playerCards[0].rank << " of " << suitToString(playerCards[0].suit) << endl;

    dealerCards[0] = deck.drawCard();
    cout << "Dealer drew " << dealerCards[0].rank << " of " << suitToString(dealerCards[0].suit) << endl;

    playerCards[1] = deck.drawCard();
    cout << "You drew a " << playerCards[1].rank << " of " << suitToString(playerCards[1].suit) << endl; 

    dealerCards[1] = deck.drawCard();

    int playerSum = playerCards[0].rank + playerCards[1].rank;
    cout << "You currently have " << playerSum << endl;

    if (playerSum == 21 && dealerCards[0].rank != 10 && dealerCards[0].rank != ACE){
        return BLACKJACK;
    } else if (playerSum == 21 && (dealerCards[0].rank == 10 || dealerCards[0].rank == ACE)) {
        cout << "You have Blackjack, dealer might also" << endl;
        cout << "Dealers second card is " << dealerCards[1].rank << " of " << suitToString(dealerCards[1].suit) << endl;
        
        if (dealerCards[0].rank == TEN && dealerCards[1].rank == ACE) {
            cout << "Dealer has Blackjack!" << endl;
            return PUSH;
        } else if (dealerCards[0].rank == ACE && dealerCards[1].rank == TEN) {
            cout << "Dealer has Blackjack!" << endl;
            return PUSH;
        }

        cout << "Dealer did not have a blackjack!" << endl;
        return BLACKJACK;
    } else if (dealerCards[0].rank == 10 || dealerCards[0].rank == ACE) {
        cout << "Dealer might have BJ, you do not" << endl;
        cout << "Insurance" << endl;
    }

    return result;
}

/*
TODO
- if dealer one is Ace or 10, ask safety
- player draw
- dealer stops only at 17+
- player may double down
- player may split
- player hit or stand
*/