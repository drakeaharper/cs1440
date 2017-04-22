//
// Created by drake on 4/15/2017.
//

#ifndef ITAK_ANALYZER_H
#define ITAK_ANALYZER_H

#include "ResultSet.h"
#include "Configuration.h"
#include "Dictionary.h"

#include <fstream>

class Analyzer
{
public:
    virtual ResultSet run() = 0;
    virtual void loadFromFile(std::string) = 0;
    virtual void attackDetection() = 0;

};


#endif //ITAK_ANALYZER_H
