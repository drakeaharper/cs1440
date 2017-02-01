//
// Created by drake on 2/1/2017.
//

#ifndef ANALYSTCOMPARER_ANALYST_H
#define ANALYSTCOMPARER_ANALYST_H

#include "History.h"
#include <iostream>
#include <string>
#include <fstream>

class Analyst
{
public:
    Analyst();
    int load(std::ifstream inputStream);
    float getStockPerformance();
    std::string getName() {return m_name;}
    std::string getInitials() {return m_initials;}
    History getHistory() {return m_histroy;}
private:
    std::string m_name;
    std::string m_initials;
    History m_history;
};


#endif //ANALYSTCOMPARER_ANALYST_H
