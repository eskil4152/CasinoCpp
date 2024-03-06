#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>
#include <algorithm>
#include <random>

enum SUIT {
    HEARTS, DIAMONDS, CLUBS, SPADES
};

enum RANK {
    //ACE = 1,
    ACE = 11,
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

    /*int getValue() const {
        if (rank == ACE){
            return 11;
        } else if (rank >= JACK && rank <= KING) {
            return 10;
        } else {
            return (int)rank;
        }
    }

    void setAceValue(int value){
        if (rank == ACE){
            value = std::clamp(value, 1, 11);
        }
    }*/
};

struct blackjackDeck{
    std::vector<card> deck;

    blackjackDeck(){
        initializeDeck();
    }

    void initializeDeck(){
        for (int suit = HEARTS; suit <= SPADES; suit++){
            for (int rank = ACE; rank <= KING; rank++){
                card newCard = { static_cast<RANK>(rank), static_cast<SUIT>(suit) };
                deck.push_back(newCard);
            }
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
            initializeDeck();
            shuffle();
            return drawCard();
        }
    }
};

#endif