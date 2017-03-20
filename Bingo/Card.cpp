//
// Created by drake on 3/2/2017.
//

#include "Card.h"

Card::Card(int size, int maxNumber, int index)
{
    m_size = size;

    if (m_size < 3)
    {
        std::cout << "Value of size " << m_size << " is invalid.\n";
        return;
    }

    m_index = index;

    if (index < 0 || index > m_size)
    {
        std::cout << "Index of " << m_index << " is invalid.\n";
        return;
    }

    m_maxNumber = maxNumber;

    if (m_maxNumber < m_size*m_size*2 || m_maxNumber > m_size*m_size*4)
    {
        std::cout << "Max value of " << m_maxNumber << " is invalid.\n";
        return;
    }

    m_position = 0;
    makeRandomArray(m_maxNumber);
}

void Card::makeRow(std::ostream& out)
{
    out << "|";
    for (int i = 0; i < m_size; i++)
    {
        int temp = getNumber();
        m_gridTracker.push_back(temp);
        out << std::setw(4) << temp << "|";
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
    std::vector<int> tempVect;
    for (int i = 1; i < max; i++)
    {
        m_numberVector.push_back(i);
        tempVect.push_back(i);

        if (m_numberVector[i - 1] > max)
        {
            std::cout << "Number at " << i - 1 << " is invalid." << std::endl;
            std::cout << "The number is " << m_numberVector[i - 1] << std::endl << std::endl;
        }
    }

    std::random_shuffle(m_numberVector.begin(), m_numberVector.end());
}

int Card::getNumber()
{
    return m_numberVector[m_position++];
}

void Card::printCard(std::ostream& out)
{
    out << "Card #" << m_index << "\n";
    for (int i = 0; i < m_size; i++)
    {
        makeBreak(out);
        makeRow(out);
    }
    makeBreak(out);
    out << "\n";
    out << "\n";
}

int Card::getGridPosition(int x, int y)
{
    int gridPosition = 0;

    if (y > 1)
    {
        int temp = (y - 1) * m_size;
        gridPosition = x + temp;
    }
    else
    {
        gridPosition = x;
    }

    return gridPosition;
}
