//
// Created by drake on 2/1/2017.
//

#include "PurchaseSale.h"

PurchaseSale::PurchaseSale(std::ifstream& inputStream)
{
    if (!inputStream.is_open() || inputStream.eof())
        return;
    std::string line;
    std::getline(inputStream, line);
    std::string fields[8];
    if (split(line, ',', fields, 8))
    {
        m_symbol = fields[0];
        m_quantity = std::stoi(fields[1]);
        m_purchaseDateTime = std::stoi(fields[2]);
        m_purchasePrice = std::stoi(fields[3]);
        m_purchaseFee = std::stoi(fields[4]);
        m_saleDateTime = std::stoi(fields[5]);
        m_salePrice = std::stoi(fields[6]);
        m_saleFee = std::stoi(fields[7]);
    }
}

int PurchaseSale::computeInvestmentAmount()
{
    return (m_quantity * m_purchasePrice) + m_purchaseFee + m_saleFee;
}

int PurchaseSale::computeProfitLoss()
{
    int investment = computeInvestmentAmount();
    return (m_quantity * m_salePrice) - investment;
}

int PurchaseSale::getPurchaseDateTime()
{
    return m_purchaseDateTime;
}

int PurchaseSale::getSaleDateTime()
{
    return m_saleDateTime;
}

std::string PurchaseSale::getSymbol()
{
    return m_symbol;
}