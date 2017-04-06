//
// Created by drake on 4/5/2017.
//

#ifndef GENERICS_TESTCASESSTRINGPOINTER_H
#define GENERICS_TESTCASESSTRINGPOINTER_H

#include <iostream>
#include <string>
#include "../Dictionary.h"

class TestCasesStringPointer
{
public:
    void run();

private:
    void testAdd(Dictionary<std::string*, std::string*>& testDictionary);
    void testGetByKey(Dictionary<std::string*, std::string*>& testDictionary, std::string* testKey);
    void testGetByIndex(Dictionary<std::string*, std::string*>& testDictionary);
    void testRemoveByKey(Dictionary<std::string*, std::string*>& testDictionary, std::string* testKey);
    void testRemoveByIndex(Dictionary<std::string*, std::string*>& testDictionary);
};


#endif //GENERICS_TESTCASESSTRINGPOINTER_H
