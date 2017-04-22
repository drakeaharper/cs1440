//
// Created by drake on 4/15/2017.
//

#ifndef ITAK_CONFIGURATION_H
#define ITAK_CONFIGURATION_H

#include <iostream>
#include <fstream>

#include "Dictionary.h"

class Configuration
{
public:
    Configuration();
    std::ofstream fout;

    void isDOS();
    void isPSA();

    void menu();
private:


};


#endif //ITAK_CONFIGURATION_H
