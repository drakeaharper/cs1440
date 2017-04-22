//
// Created by drake on 4/22/2017.
//

#ifndef ITAK_TESTDENIAL_H
#define ITAK_TESTDENIAL_H

#include "../DenialOfServiceAnalyzer.h"

class TestDenial
{
public:
    void run();
    void testLoadFromFile(DenialOfServiceAnalyzer denial);
    void testAttackDetection();
};


#endif //ITAK_TESTDENIAL_H
