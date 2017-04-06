//
// Created by drake on 4/5/2017.
//

#ifndef GENERICS_TESTCASESINT_H
#define GENERICS_TESTCASESINT_H

#include <iostream>
#include <string>
#include "../Dictionary.h"

class TestCasesInt
{
public:
    void run();

private:
    void testAdd(Dictionary<int, int>& testDictionary);
    void testGetByKey(Dictionary<int, int>& testDictionary);
    void testGetByIndex(Dictionary<int, int>& testDictionary);
    void testRemoveByKey(Dictionary<int, int>& testDictionary);
    void testRemoveByIndex(Dictionary<int, int>& testDictionary);
};


#endif //GENERICS_TESTCASESINT_H
