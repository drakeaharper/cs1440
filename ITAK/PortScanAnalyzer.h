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
    void loadFromFile(std::string file);
    void attackDetection();

private:
    unsigned int likeyAttackPort;
    unsigned int possibleAttackCount;
    Dictionary<std::string, std::vector<std::string>> m_dictionary;
};


#endif //ITAK_PORTSCANANALYZER_H
