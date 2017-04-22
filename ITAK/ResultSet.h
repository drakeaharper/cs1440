//
// Created by drake on 4/15/2017.
//

#ifndef ITAK_RESULTSET_H
#define ITAK_RESULTSET_H

#include <iostream>
#include <fstream>
#include <string>

#include "Dictionary.h"

class ResultSet
{
public:
    void print(std::ostream& out, Dictionary<std::string, std::vector<std::string>> output);
};


#endif //ITAK_RESULTSET_H
