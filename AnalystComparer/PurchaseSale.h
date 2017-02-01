//
// Created by drake on 2/1/2017.
//

#ifndef ANALYSTCOMPARER_PURCHASESALE_H
#define ANALYSTCOMPARER_PURCHASESALE_H


class PurchaseSale
{
public:
    PurchaseSale(ifstream inputStream);
    std::string getSymbol();
    int getPurchaseDateTime();
    int getSaleDateTime();
    int computeInvestmentAmount();
    int computeProfitLoss();

private:
    std::string m_symbol;
    int m_quantity;
    int m_purchaseDateTime;
    int m_purchasePrice;
    int m_purchaseFee;
    int m_saleDateTime;
    int m_salePrice;
    int m_saleFee;
};


#endif //ANALYSTCOMPARER_PURCHASESALE_H
