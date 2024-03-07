#include "games/blackjack/blackjackDeck.h"

BlackjackDeck::BlackjackDeck() {
    initializeDeck();
    shuffle();
}

void BlackjackDeck::initializeDeck() {
    deck.clear();
    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int rank = ACE; rank <= KING; rank++) {
            card newCard = {static_cast<RANK>(rank), static_cast<SUIT>(suit)};
            deck.push_back(newCard);
        }
    }
}

void BlackjackDeck::shuffle() {
    std::random_device random;
    std::mt19937_64 rng(random());
    std::shuffle(deck.begin(), deck.end(), rng);
}

card BlackjackDeck::drawCard() {
    if (!deck.empty()) {
        card drawnCard = deck.back();
        deck.pop_back();
        return drawnCard;
    } else {
        std::cerr << "Error: Deck is empty!" << std::endl;
        exit(1);
    }
}

std::string suitToString(SUIT suit) {
    switch (suit) {
        case HEARTS:
            return "HEARTS";
        case DIAMONDS:
            return "DIAMONDS";
        case CLUBS:
            return "CLUBS";
        case SPADES:
            return "SPADES";
        default:
            return "UNKNOWN";
    }
}

int calculateHandValue(const std::vector<card> &hand) {
    int handValue = 0;
    int aces = 0;

    for (const auto &handCard : hand) {
        std::cout << "Card: " << handCard.rank << " of " << suitToString(handCard.suit) << std::endl;
        if (handCard.rank == ACE) {
            aces++;
            handValue += 11;
        } else {
            handValue += handCard.rank;
        }
    }

    while (handValue > 21 && aces > 0) {
        aces--;
        handValue -= 10;
    }

    return handValue;
}