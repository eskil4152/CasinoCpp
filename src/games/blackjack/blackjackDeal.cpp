#include "games/blackjack/blackjackResult.h"
#include "games/blackjack/blackjackDeal.h"
#include "games/blackjack/blackjackInputs.h"

#include "tools/cardDeck.h"

#include <iostream>

using namespace std;
BlackjackResult deal(){
    CardDeck deck;

    bool draw = false;

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
        cout << "   " << rankToString(playerCard.rank) << " of " << suitToString(playerCard.suit) << endl;
    }

    int dealerSum = calculateBlackjackHand(dealerCards);
    int playerSum = calculateBlackjackHand(playerCards);
    cout << "Your current hand value: " << playerSum << endl; 

    if (playerSum == 21 && dealerSum != 21){
        cout << "You have Blackjack!" << endl;
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
        cout << "Insurance not implemented" << endl;

        if (dealerSum == 21){
            return LOSE;
        }
    }

    draw = blackjackHit();

    bool over21 = false;
    while (draw && !over21){
        card newCard = deck.drawCard();
        playerCards.push_back(newCard);

        cout << "You drew a " << newCard.rank << " of " << suitToString(newCard.suit) << endl;
        cout << "Your current hand value: " << calculateBlackjackHand(playerCards) << endl;
        
        if (calculateBlackjackHand(playerCards) >= 21){
            over21 = true;
        } else {
            draw = blackjackHit();
        }
    }

    if (calculateBlackjackHand(playerCards) > 21){
        cout << "You busted" << endl;
        return LOSE;
    }

    cout << "Dealers second car was a " << dealerCards[1].rank << " of " << suitToString(dealerCards[1].suit) << endl;
    cout << "Dealer has " << calculateBlackjackHand(dealerCards) << endl;

    while (calculateBlackjackHand(dealerCards) < 17){
        card newCard = deck.drawCard();
        dealerCards.push_back(newCard);

        cout << "Dealer drew a " << newCard.rank << " of " << suitToString(newCard.suit) << endl;
        cout << "Dealer has: " << calculateBlackjackHand(dealerCards) << endl;
    }

    if (calculateBlackjackHand(dealerCards) > 21){
        cout << "Dealer busted, you win" << endl;
        return WIN;
    } else if (calculateBlackjackHand(dealerCards) > calculateBlackjackHand(playerCards)){
        cout << "You lost..." << endl;
        return LOSE;
    } else if (calculateBlackjackHand(dealerCards) == calculateBlackjackHand(playerCards)){
        cout << "Bet pushed" << endl; 
        return PUSH;
    }

    cout << "You won!" << endl;
    return WIN;
}

/*
TODO
- ask insurance
- double down
- split
*/