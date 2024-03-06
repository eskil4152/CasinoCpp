#include "games/blackjack/blackjackResult.h"
#include "games/blackjack/blackjackDeal.h"
#include "games/blackjack/blackjackDeck.h"

#include <iostream>

using namespace std;
BlackjackResult deal(){
    BlackjackDeck deck;
    BlackjackResult result;

    deck.shuffle();

    vector<card> dealerCards;
    vector<card> playerCards;

    for (int i = 0; i < 2; i++){
        playerCards.push_back(deck.drawCard());
        dealerCards.push_back(deck.drawCard());
    }

    cout << "Dealer has " << dealerCards[0].rank << " of " << suitToString(dealerCards[0].suit) << endl;
    
    cout << "Your hand: " << endl;
    for (const auto& playerCard : playerCards) {
        cout << "   " << playerCard.rank << " of " << suitToString(playerCard.suit) << endl;
    }

    int dealerSum = calculateHandValue(dealerCards);
    int playerSum = calculateHandValue(playerCards);
    cout << "Your current hand value: " << playerSum << endl; 

    if (playerSum == 21 && dealerSum != 21){
        return BLACKJACK;
    } else if (playerSum == 21 && (dealerCards[0].rank == 10 || dealerCards[0].rank == ACE)) {
        cout << "You have Blackjack, dealer might also" << endl;
        cout << "Dealers second card is " << dealerCards[1].rank << " of " << suitToString(dealerCards[1].suit) << endl;
        
        if (dealerSum == 21) {
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