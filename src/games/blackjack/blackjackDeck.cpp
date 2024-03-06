/*#include "games/blackjack/blackjackDeck.h"
#include <algorithm>
#include <random>

blackjackDeck::blackjackDeck() {
    initializeDeck();
}

void blackjackDeck::initializeDeck() {
    for (int s = HEARTS; s <= SPADES; ++s) {
        for (int r = ACE; r <= KING; ++r) {
            cards.push_back({ static_cast<RANK>(r), static_cast<SUIT>(s) });
        }
    }
}

void blackjackDeck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(cards.begin(), cards.end(), rng);
}

card blackjackDeck::drawCard() {
    if (!cards.empty()) {
        card drawnCard = cards.back();
        cards.pop_back();
        return drawnCard;
    } else {
        return { ACE, HEARTS };
    }
}
*/