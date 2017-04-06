//
// Created by drake on 4/3/2017.
//

#include <iostream>

#include "../Dictionary.h"
#include "TestCasesInt.h"
#include "TestCasesString.h"
#include "TestCasesStringPointer.h"
#include "TestCasesCopyConstructors.h"

int main()
{
    std::cout << "Running TestCasesString." << std::endl;
    TestCasesString stringTest;
    stringTest.run();
    std::cout << std::endl;

    std::cout << "Running TestCasesInt." << std::endl;
    TestCasesInt intTest;
    intTest.run();
    std::cout << std::endl;

    std::cout << "Running TestCasesStringPointer." << std::endl;
    TestCasesStringPointer pointerTest;
    pointerTest.run();
    std::cout << std::endl;

    std::cout << "Testing Copy Constructors." << std::endl;
    TestCasesCopyConstructors testCopy;
    testCopy.run();


    return 0;
}