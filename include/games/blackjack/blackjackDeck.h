#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

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
    JACK = 10,
    QUEEN = 10,
    KING = 10
};

struct card {
    RANK rank;
    SUIT suit;
};

struct BlackjackDeck{
    std::vector<card> deck;

    BlackjackDeck(){
        initializeDeck();
        shuffle();
    }

    void initializeDeck(){
        deck.clear();
        for (int suit = HEARTS; suit <= SPADES; suit++){
            for (int rank = ACE; rank <= KING; rank++){
                card newCard = { static_cast<RANK>(rank), static_cast<SUIT>(suit) };
                deck.push_back(newCard);
            }
            std::cout << deck.size() << std::endl;
        }
    }

    void shuffle(){
        std::random_device random;
        std::mt19937_64 rng(random());
        std::shuffle(deck.begin(), deck.end(), random);
    }

    card drawCard(){
        if (!deck.empty()){
            card drawnCard = deck.back();
            deck.pop_back();
            return drawnCard;
        } else {
            std::cerr << "Error: Deck is empty!" << std::endl;
            exit(1);
        }
    }
};

std::string suitToString(SUIT suit) {
    switch (suit) {
        case HEARTS: return "HEARTS";
        case DIAMONDS: return "DIAMONDS";
        case CLUBS: return "CLUBS";
        case SPADES: return "SPADES";
        default: return "UNKNOWN";
    }
}

#endif