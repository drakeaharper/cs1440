//
// Created by drake on 4/15/2017.
//

#include "PortScanAnalyzer.h"

ResultSet PortScanAnalyzer::run()
{
    std::ifstream in;
    in.open("PortFile.txt");

    in >> likeyAttackPort;
    in >> possibleAttackCount;


    std::string file;
    std::cout << "Enter file to load data from: ";
    std::cin >> file;

    // load file into m_dictionary
    loadFromFile(file);

    // run attack detection algorithm
    attackDetection();
}

void PortScanAnalyzer::loadFromFile(std::string file)
{
    std::ifstream in;
    in.open(file);
    unsigned int lineCounter = 0;

    while (lineCounter < 10)
    {
        std::string ss;
        getline(in, ss);

        std::string fields[4];
        int fieldPosition = 0;

        for (unsigned int index = 0; index < ss.length() && fieldPosition < 4; index++)
        {
            if (ss[index] == ',')
            {
                index++;
                fieldPosition++;
            }

            fields[fieldPosition] += ss[index];
        }

        std::vector<std::string> temp;

        bool exist = false;

        for (unsigned int i = 0; i < m_dictionary.getTotalEntries(); i++)
        {
            if (fields[1] == m_dictionary.getByIndex(i).getKey())
            {
                exist = true;
            }
        }

        if (exist)
        {
            temp = m_dictionary.getByKey(fields[1]).getValue();
            temp.push_back(fields[3]);
            m_dictionary.getByKey(fields[1]).setValue(temp);
        }
        else
        {
            temp.push_back(fields[3]);
            m_dictionary.getByKey(fields[1]).setValue(temp);

        }

        lineCounter++;
    }
}

void PortScanAnalyzer::attackDetection()
{

}