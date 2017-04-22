//
// Created by drake on 4/11/2017.
//

#include <iostream>
#include "TestDenial.h"

int main()
{
    std::cout << "Running test cases." << std::endl;

    std::cout << "Testing Denial of Service Analzer." << std::endl;
    TestDenial d;
    d.run();

    return 0;
}