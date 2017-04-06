//
// Created by drake on 4/3/2017.
//

#ifndef GENERICS_KEYVALUETESTER_H
#define GENERICS_KEYVALUETESTER_H

#include <iostream>
#include <string>
#include "../Dictionary.h"

class TestCasesString
{
public:
    void run();

private:
    void testAdd(Dictionary<std::string, std::string>& testDictionary);
    void testGetByKey(Dictionary<std::string, std::string>& testDictionary);
    void testGetByIndex(Dictionary<std::string, std::string>& testDictionary);
    void testRemoveByKey(Dictionary<std::string, std::string>& testDictionary);
    void testRemoveByIndex(Dictionary<std::string, std::string>& testDictionary);
};

// TODO: Notes
// Need to find a way to prevent invalid data being entered in for find index and remove by index functions
// // not too high or too low but entering in a letter or symbol.

#endif //GENERICS_KEYVALUETESTER_H
