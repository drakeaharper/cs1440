//
// Created by drake on 4/15/2017.
//

#include "Configuration.h"
#include "DenialOfServiceAnalyzer.h"
#include "PortScanAnalyzer.h"

#include <iostream>

Configuration::Configuration()
{
    char input = 'x';
    menu();
    std::cin >> input;

    switch (input)
    {
        case 'D':
            isDOS();
            break;

        case 'P':
            isPSA();
            break;

        default:
            std::cout << "Unrecognized input." << std::endl;
            break;
    }
}

void Configuration::menu()
{
    std::cout << "Choose a command: \n"
              << "D - Denial of service analyzer\n"
              << "P - Port scan analyzer\n";
}

void Configuration::isDOS()
{
    char input = 'x';
    bool valid;
    do
    {
        std::cout << "Read data from file? <Enter y or n> ";
        std::cin >> input;

        if (input == 'y')
        {
            valid = true;
        }
        if (input == 'n')
        {
            valid = true;
        }

    } while(!valid);
    bool fromFile;

    fromFile = (input == 'y');

    fout.open("DenialFile.txt");

    if (!fromFile)
    {
        int x = 0;

        std::cout << "Enter start time: ";
        std::cin >> x;
        fout << x << std::endl;

        std::cout << "Enter end time: ";
        std::cin >> x;
        fout << x << std::endl;

        std::cout << "Enter likely attack count: ";
        std::cin >> x;
        fout << x << std::endl;

        std::cout << "Enter possible attack count: ";
        std::cin >> x;
        fout << x << std::endl;

        fout.close();
    }
    else
    {
        std::ifstream input;

    }
}

void Configuration::isPSA()
{

}
