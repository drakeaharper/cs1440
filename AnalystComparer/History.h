//
// Created by drake on 2/1/2017.
//

#ifndef ANALYSTCOMPARER_HISTORY_H
#define ANALYSTCOMPARER_HISTORY_H

#include "PurchaseSale.h"
#include <iostream>
#include <string>
#include <fstream>

class History
{
public:
    void load(std::ifstream& inputStream);
    int getSimulationDays();
    int getInitialMoney();
    int computeTotalProfitLoss();
    int computeProfitLossPerDay();
    void resetIterator();
    PurchaseSale nextPurchaseSale();
    bool hasNext();

private:
    int m_simulationDays;
    int m_seedMoney;
    PurchaseSale** m_purchaseSales;
    int m_purchaseSalesCount;
    int m_currentPurchaseSale;
};


#endif //ANALYSTCOMPARER_HISTORY_H
