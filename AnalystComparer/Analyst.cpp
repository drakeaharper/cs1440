//
// Created by drake on 2/1/2017.
//

#include "Analyst.h"
#include "Utils.h"

void Analyst::load(std::ifstream& inputStream)
{
    m_name = getTrimmedLine(inputStream);
    m_initials = getTrimmedLine(inputStream);

    m_history.load(inputStream);
}

float Analyst::getStockPerformance(std::string symbol)
{
    float symbolTotal = 0;
    m_history.resetIterator();

    while (m_history.hasNext())
    {
        PurchaseSale nextPS = m_history.nextPurchaseSale();

        if (nextPS.getSymbol() == symbol)
        {
            symbolTotal += nextPS.computeProfitLoss();
        }
    }
}