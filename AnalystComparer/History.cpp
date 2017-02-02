//
// Created by drake on 2/1/2017.
//

#include "History.h"
#include "Utils.h"

void History::load(std::ifstream& inputStream)
{
    while (inputStream.is_open() && !inputStream.eof())
    {
        std::string line = getTrimmedLine(inputStream);
        m_simulationDays = stoi(line);

        line = getTrimmedLine(inputStream);
        m_seedMoney = stoi(line);

        line = getTrimmedLine(inputStream);
        m_purchaseSalesCount = stoi(line);
    }

    m_purchaseSales = new PurchaseSale*[m_purchaseSalesCount];

    for (int i = 0; i < m_purchaseSalesCount; i++)
    {
        m_purchaseSales[i] = new PurchaseSale(inputStream);
    }



}

int History::getSimulationDays()
{
    return m_simulationDays;
}

int History::getInitialMoney()
{
    return m_seedMoney;
}

int History::computeTotalProfitLoss()
{
    int totalProfitLoss = getInitialMoney();
    for (int i = 0; i < m_purchaseSalesCount; i++)
    {
        totalProfitLoss += m_purchaseSales[i]->computeProfitLoss();
    }

    return totalProfitLoss;
}

int History::computeProfitLossPerDay()
{
    int profitLossPerDay = computeTotalProfitLoss() / getSimulationDays();

    return profitLossPerDay;
}

void History::resetIterator()
{
    m_currentPurchaseSale = 0;
}

PurchaseSale History::nextPurchaseSale()
{
    if (hasNext())
    {
        return *m_purchaseSales[m_currentPurchaseSale++];
    }
    else
    {
        return NULL;
    }
}

bool History::hasNext()
{
    return (m_currentPurchaseSale < m_purchaseSalesCount);
}