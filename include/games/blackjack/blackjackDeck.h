#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <map>

enum SUIT {
    HEARTS, DIAMONDS, CLUBS, SPADES
};

enum RANK {
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13
};

struct card {
    RANK rank;
    SUIT suit;
};

class BlackjackDeck {
public:
    std::vector<card> deck;

    BlackjackDeck();

    void initializeDeck();
    void shuffle();
    card drawCard();
};

std::string rankToString(RANK rank);

std::string suitToString(SUIT suit);

int calculateHandValue(const std::vector<card>& hand);

#endif
