//
// Created by drake on 4/22/2017.
//

#ifndef ITAK_TESTPORTSCAN_H
#define ITAK_TESTPORTSCAN_H

#include "../PortScanAnalyzer.h"

class TestPortScan
{
    void run();
    void testLoadFromFile(PortScanAnalyzer port);
    void testAttackDetection();
};


#endif //ITAK_TESTPORTSCAN_H
