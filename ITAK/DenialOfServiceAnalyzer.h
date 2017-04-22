//
// Created by drake on 4/15/2017.
//

#ifndef ITAK_DENIALOFSERVICEANALYZER_H
#define ITAK_DENIALOFSERVICEANALYZER_H

#include "Analyzer.h"

class DenialOfServiceAnalyzer : public Analyzer
{
public:
    ResultSet run();
    virtual void loadFromFile(std::string);
    virtual void attackDetection();
    
    void setTFS(unsigned int toSet) { m_TFS = toSet; }
    void setTFE(unsigned int toSet) { m_TFE = toSet; }
    void setLikely(unsigned int toSet) { m_likelyCount = toSet; }
    void setPossible(unsigned int toSet) { m_possibleCount = toSet; }
    Dictionary<std::string, Dictionary<std::string, long>> getDictionary() { return m_dictionary; }

private:
    std::istream m_in;
    Dictionary<std::string, Dictionary<std::string, long>> m_dictionary;
    unsigned int m_TFS;
    unsigned int m_TFE;
    unsigned int m_likelyCount;
    unsigned int m_possibleCount;

};


#endif //ITAK_DENIALOFSERVICEANALYZER_H
