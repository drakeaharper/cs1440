//
// Created by drake on 4/3/2017.
//

#include <iostream>

#include "../Dictionary.h"
#include "../KeyValue.h"

#include "KeyValueTester.h"

int main()
{
    std::cout << "Running KeyValue tester." << std::endl;
    KeyValue<std::string, std::string> m_keyValue;
    KeyValueTester KVTester;
    KVTester.run();

}