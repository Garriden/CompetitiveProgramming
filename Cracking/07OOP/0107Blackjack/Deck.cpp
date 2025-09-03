#include "Deck.hpp"
#include "DeckHelper.hpp"
#include <iostream>

Deck::Deck()
{
    int paleCount = static_cast<int>(Pale::SIZE);
    int numberCount = static_cast<int>(Number::SIZE);

    for(int ii = 0; ii < paleCount; ++ii) {
        for(int jj = 0; jj < numberCount; ++jj) {
            Pale currentPale = static_cast<Pale>(ii);
            Number currentNumber = static_cast<Number>(jj);
            
            Card card(currentPale, currentNumber);
            _deck.push_back(card);
        }
    }

}

void Deck::PrintDeck() const
{
    for(int ii = 0; ii < DECK_SIZE; ++ii) {
        std::cout << DeckHelper::NumberToString(_deck[ii].GetNumber()) << " " << DeckHelper::PaleToString(_deck[ii].GetPale()) << ",  ";
    } std::cout << std::endl;
}