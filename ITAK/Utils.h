//
// Created by drake on 4/11/2017.
//

#ifndef ITAK_UTILS_H
#define ITAK_UTILS_H

#include <ios>
#include <fstream>
#include "Dictionary.h"

class Utils
{
public:
    void buildDictionary(Dictionary<std::string, KeyValue<std::string, KeyValue<std::string, std::string>>>& baseDictionary, std::ifstream& in);

};


#endif //ITAK_UTILS_H
