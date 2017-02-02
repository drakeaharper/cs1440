//
// Created by drake on 2/1/2017.
//

#include "Analyst.h"
#include "Utils.h"

Analyst::Analyst()
{

}

int Analyst::load(std::ifstream& inputStream)
{
    m_name = getTrimmedLine(inputStream);
    m_initials = getTrimmedLine(inputStream);
}

float getStockPerformance()
{

}