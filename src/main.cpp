#include "tools/checkInput.h"
#include "start.h"
#include "user/userdata.h"

#include "games/blackjack/blackjackDeck.h"

#include <iostream>

using namespace std;
int main(){
    cout << std::endl << std::endl << std::endl << endl;
    cout << "Hello and welcome to the casino" << endl;

    setName(nameInput());
    start();

    /*
    BlackjackDeck deck;
    deck.shuffle();
    int value = 0;

    std::vector<card> hand;
    card cardOne = deck.drawCard();
    card cardTwo = deck.drawCard();

    cout << "drew a " << cardOne.rank << " of " << suitToString(cardOne.suit) << endl;
    cout << "drew a " << cardTwo.rank << " of " << suitToString(cardTwo.suit) << endl;

    hand.push_back(cardOne);
    hand.push_back(cardTwo);

    cout << "Total: " << calculateHandValue(hand) << endl;

    card cardThree = deck.drawCard();
    cout << "drew a " << cardThree.rank << " of " << suitToString(cardThree.suit) << endl;
    hand.push_back(cardThree);
    cout << "Total: " << calculateHandValue(hand) << endl;

    card cardFour = deck.drawCard();
    cout << "drew a " << cardFour.rank << " of " << suitToString(cardFour.suit) << endl;
    hand.push_back(cardFour);
    cout << "Total: " << calculateHandValue(hand) << endl;

    card cardFive = deck.drawCard();
    cout << "drew a " << cardFive.rank << " of " << suitToString(cardFive.suit) << endl;
    hand.push_back(cardFive);
    cout << "Total: " << calculateHandValue(hand) << endl;
    */

    return 0;
}