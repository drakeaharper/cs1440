//
// Created by Stephen Clyde on 2/16/17.
//

#include "Deck.h"

Deck::Deck(int cardSize, int cardCount, int numberMax)
{
    // TODO: Implement
    m_howMany = cardCount;
    myCards = new Card*[cardCount];

    for (int i = 0; i < cardCount; i++)
    {
        myCards[i] = new Card(cardSize, numberMax, i);
    }
}

Deck::~Deck()
{
    // TODO: Implement
    for (int i = 0; i < m_howMany; i++)
    {
        delete myCards[i];
    }
    delete [] myCards;
}

void Deck::print(std::ostream& out) const
{
    // TODO: Implement
    for (int i = 0; i < m_howMany; i++)
    {
        myCards[i]->printCard(out);
    }
}

void Deck::print(std::ostream& out, int cardIndex) const
{
    // TODO: Implement
    myCards[cardIndex]->printCard(out);
}



