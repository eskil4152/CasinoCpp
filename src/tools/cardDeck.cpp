#include "tools/cardDeck.h"

CardDeck::CardDeck() {
    initializeDeck();
    shuffle();
}

void CardDeck::initializeDeck() {
    deck.clear();
    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int rank = ACE; rank <= KING; rank++) {
            card newCard = {static_cast<RANK>(rank), static_cast<SUIT>(suit)};
            deck.push_back(newCard);
        }
    }
}

void CardDeck::shuffle() {
    std::random_device random;
    std::mt19937_64 rng(random());
    std::shuffle(deck.begin(), deck.end(), rng);
}

card CardDeck::drawCard() {
    if (!deck.empty()) {
        card drawnCard = deck.back();
        deck.pop_back();
        return drawnCard;
    } else {
        std::cerr << "Error: Deck is empty!" << std::endl;
        exit(1);
    }
}

std::string rankToString(RANK rank) {
    switch (rank) {
        case ACE: return "ACE";
        case TWO: return "TWO";
        case THREE: return "THREE";
        case FOUR: return "FOUR";
        case FIVE: return "FIVE";
        case SIX: return "SIX";
        case SEVEN: return "SEVEN";
        case EIGHT: return "EIGHT";
        case NINE: return "NINE";
        case TEN: return "TEN";
        case JACK: return "JACK";
        case QUEEN: return "QUEEN";
        case KING: return "KING";
        default: return "UNKNOWN";
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

int calculateBlackjackHand(const std::vector<card> &hand) {
    int handValue = 0;
    int aces = 0;

    for (const auto &handCard : hand) {
        if (handCard.rank == ACE) {
            aces++;
            handValue += 11;
        } else if (handCard.rank == JACK || handCard.rank == QUEEN || handCard.rank == KING) {
            handValue += 10;
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