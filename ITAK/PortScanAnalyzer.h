//
// Created by drake on 4/15/2017.
//

#ifndef ITAK_PORTSCANANALYZER_H
#define ITAK_PORTSCANANALYZER_H

#include "Analyzer.h"

class PortScanAnalyzer : public Analyzer
{
public:
    ResultSet run();
    virtual void loadFromFile(std::string);
    virtual void attackDetection();

private:
    // 	“Likely	Attack	Port	Count”	and	“Possible	Attack	Port	Count”

    unsigned int likeyAttackPort;
    unsigned int possibleAttackCount;
};


#endif //ITAK_PORTSCANANALYZER_H
