//
// Created by drake on 3/2/2017.
//

#ifndef BINGO_CARD_H
#define BINGO_CARD_H

#include <string>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <vector>
#include <algorithm>

class Card
{
public:
    Card(int size, int maxNumber, int index);
    void makeRow(std::ostream& out);
    void makeBreak(std::ostream& out);
    void makeRandomArray(int max);
    int getNumber();
    void printCard(std::ostream& out);


private:
    std::vector<int> m_numberVector;
    unsigned int m_position;
    int m_size;
    int m_maxNumber;
    int m_index;
};


#endif //BINGO_CARD_H
