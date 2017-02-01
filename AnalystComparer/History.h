//
// Created by drake on 2/1/2017.
//

#ifndef ANALYSTCOMPARER_HISTORY_H
#define ANALYSTCOMPARER_HISTORY_H


class History
{
public:
    History();
    int load(ifstream inputStream);
    int getSimulationDays();
    int getInitialMoney();
    int computeTotalProfitLoss();
    int computeProfitLossPerDay();
    void resetIteration();
    PurchaseSale nextPurchaseSale();
private:
    int m_simulationDays;
    int m_seedMoney;
    PurchaseSale** m_purchaseSales;
    int m_purchaseSalesCount;
    int m_currentPurchaseSale;
};


#endif //ANALYSTCOMPARER_HISTORY_H
