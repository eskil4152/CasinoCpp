#include "games/blackjack/blackjackResult.h"
#include "games/blackjack/blackjackDeal.h"
#include "games/blackjack/blackjackDeck.h"
#include "games/blackjack/blackjackInputs.h"

#include <iostream>

using namespace std;
BlackjackResult deal(){
    BlackjackDeck deck;

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
        cout << "   " << playerCard.rank << " of " << suitToString(playerCard.suit) << endl;
    }

    int dealerSum = calculateHandValue(dealerCards);
    int playerSum = calculateHandValue(playerCards);
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

    while (draw){
        card newCard = deck.drawCard();
        playerCards.push_back(deck.drawCard());

        cout << "You drew a " << newCard.rank << " of " << suitToString(newCard.suit) << endl;
        cout << "Your current hand value: " << calculateHandValue(playerCards) << endl;

        if (calculateHandValue(playerCards) >= 21){
            break;
        }

        draw = blackjackHit();
    }

    if (calculateHandValue(playerCards) > 21){
        cout << "You busted" << endl;
        return LOSE;
    }

    cout << "Dealers second car was a " << dealerCards[1].rank << " of " << suitToString(dealerCards[1].suit) << endl;
    cout << "Dealer has " << calculateHandValue(dealerCards) << endl;

    while (calculateHandValue(dealerCards) < 17){
        card newCard = deck.drawCard();
        dealerCards.push_back(newCard);

        cout << "Dealer drew a " << newCard.rank << " of " << suitToString(newCard.suit) << endl;
        cout << "Dealer has: " << calculateHandValue(dealerCards) << endl;
    }

    if (calculateHandValue(dealerCards) > 21){
        cout << "Dealer busted, you win" << endl;
        return WIN;
    } else if (calculateHandValue(dealerCards) > calculateHandValue(playerCards)){
        cout << "You lost..." << endl;
        return LOSE;
    } else if (calculateHandValue(dealerCards) == calculateHandValue(playerCards)){
        cout << "Bet pushed" << endl;
        return PUSH;
    }

    cout << "You won!" << endl;
    return WIN;
}

/*
TODO
- if dealer one is Ace or 10, ask safety
- player may double down
- player may split
*/