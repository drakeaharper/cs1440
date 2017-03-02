//
// Created by drake on 3/2/2017.
//

#include "Card.h"

Card::Card(int size, int maxNumber, int index)
{
    m_size = size;
    m_index = index;
    m_maxNumber = maxNumber;
    makeRandomArray(m_maxNumber);
}

void Card::makeRow(std::ostream& out)
{
    out << "|";
    for (int i = 0; i < m_size; i++)
    {
        out << std::setw(4) << getNumber() << "|";
    }
    out << "\n";
}

void Card::makeBreak(std::ostream& out)
{
    out << "+";
    for (int i = 0; i < m_size; i++)
    {
        out << "----+";
    }
    out << "\n";
}

void Card::makeRandomArray(int max)
{
    for (int i = 0; i < max; i++)
    {
        m_numberVector.push_back(i);
    }

    std::random_shuffle(m_numberVector.begin(), m_numberVector.end());
}

int Card::getNumber()
{
    return m_numberVector[m_position++];
}

void Card::printCard(std::ostream& out)
{
    for (int i = 0; i < m_size; i++)
    {
        makeBreak(out);
        makeRow(out);
    }
}