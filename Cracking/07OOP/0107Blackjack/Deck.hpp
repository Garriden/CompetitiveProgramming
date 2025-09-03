#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include "DeckEnums.hpp"

static constexpr int DECK_SIZE = static_cast<int>(Number::SIZE) * static_cast<int>(Pale::SIZE); // Jokers not included.

class Card {
public:
    Card(Pale p, Number n) : _pale(p), _number(n) {}
    Number GetNumber() const { return _number; }
    Pale GetPale() const { return _pale; }
private:
    Pale _pale;
    Number _number;
};

class Deck {
public:
    Deck();
    void PrintDeck() const;
private:
    std::vector<Card> _deck;
};


#endif