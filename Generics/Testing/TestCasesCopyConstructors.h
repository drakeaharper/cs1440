//
// Created by drake on 4/5/2017.
//

#ifndef GENERICS_TESTCASESCOPYCONSTRUCTORS_H
#define GENERICS_TESTCASESCOPYCONSTRUCTORS_H

#include <iostream>
#include <string>
#include "../Dictionary.h"

class TestCasesCopyConstructors
{
public:
    void run();

private:
    void compareDictionaries(Dictionary<std::string, std::string> original, Dictionary<std::string, std::string> copied);
    void compareKeyValues(KeyValue<std::string, std::string> original, KeyValue<std::string, std::string> copied);
};


#endif //GENERICS_TESTCASESCOPYCONSTRUCTORS_H
