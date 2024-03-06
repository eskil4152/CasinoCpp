#include "games/blackjack/blackjackResult.h"
#include "games/blackjack/blackjackDeal.h"
#include "games/blackjack/blackjackDeck.h"

#include <iostream>

using namespace std;
BlackjackResult deal(){
    blackjackDeck deck;
    deck.shuffle();

    card dealerCards[2];
    card playerCards[2];

    playerCards[0] = deck.drawCard();
    cout << "You drew a " << playerCards[0].rank << " of " << playerCards[0].suit << endl;

    dealerCards[0] = deck.drawCard();
    cout << "Dealer drew " << dealerCards[0].rank << " of " << dealerCards[0].suit << endl;

    playerCards[1] = deck.drawCard();
    cout << "You drew a " << playerCards[1].rank << " of " << playerCards[1].suit << endl; 

    dealerCards[1] = deck.drawCard();

    int playerSum = playerCards[0].rank + playerCards[1].rank;
    cout << "You currently have " << playerSum << endl;

    BlackjackResult result;
    result.blackjack = true;
    result.won = true;

    return result;
}

/*
TODO
- dealer draw one
- dealer draw two
- if dealer one is Ace or 10, ask safety
- player draw
- dealer stops only at 17+
- player may double down
- player may split
- player hit or stand
*/