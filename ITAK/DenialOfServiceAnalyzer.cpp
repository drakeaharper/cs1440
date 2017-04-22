//
// Created by drake on 4/15/2017.
//

#include "DenialOfServiceAnalyzer.h"

ResultSet DenialOfServiceAnalyzer::run()
{
    Configuration setParameters;

    std::ifstream in;
    in.open("DenialFile.txt");

    in >> m_TFS;
    in >> m_TFE;
    in >> m_likelyCount;
    in >> m_possibleCount;

    std::string file;
    std::cout << "Enter file name: ";
    std::cin >> file;

    // load file into m_dictionary
    loadFromFile(file);

    // run attack detection algorithm
    attackDetection();
}

void DenialOfServiceAnalyzer::loadFromFile(std::string file)
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

        for (unsigned int index = 0; index < ss.length() && fieldPosition < 4; index++ )
        {
            if (ss[index] == ',')
            {
                index++;
                fieldPosition++;
            }

            fields[fieldPosition] += ss[index];
        }

        try
        {
            m_dictionary.getByKey(fields[1]); // checks if IP address is in dictionary

            try
            {
                m_dictionary.getByKey(fields[1]).getValue().getByKey(fields[0]); // checks for time stamp, if not found throws error, goes to catch
                int tempCounter = m_dictionary.getByKey(fields[1]).getValue().getByKey(fields[0]).getValue(); // if is found gets count at timestamp
                m_dictionary.getByKey(fields[1]).getValue().getByKey(fields[0]).setValue(++tempCounter); // adds 1 to count and puts it in dictionary
            }
            catch (std::domain_error)
            {
                m_dictionary.getByKey(fields[1]).getValue().addKeyValue(fields[0], 1); // timestamp was not found so add it to dictionary with count of 1
            }
        }
        catch (std::domain_error) // adds IP address, timestamp, and count with value of 1
        {
            Dictionary<std::string, long> tempD;
            tempD.addKeyValue(fields[0], 1);
            m_dictionary.addKeyValue(fields[1], tempD);
        }

        lineCounter++;
    }

    in.close();
}

void DenialOfServiceAnalyzer::attackDetection()
{
    unsigned int timeFrame = m_TFE - m_TFS;
    ResultSet result;
    Dictionary<std::string, std::vector<std::string>> theHappenings;
    std::vector<std::string> likely;
    std::vector<std::string> possible;


    while (m_TFE < m_dictionary.getTotalEntries())
    {
        unsigned int attackCount = 0;
        for (unsigned int i = 0; i < m_dictionary.getTotalEntries() - 1; i++)
        {
            attackCount = 0;
            for (unsigned int j = 0; j < m_dictionary.getByIndex(i).getValue().getTotalEntries(); j++)
            {
                if (stol(m_dictionary.getByIndex(i).getValue().getByIndex(j).getKey()) >= m_TFS
                    && stol(m_dictionary.getByIndex(i).getValue().getByIndex(j).getKey()) <= m_TFE)
                {
                    attackCount += m_dictionary.getByIndex(i).getValue().getByIndex(j).getValue();
                }
            }

            if (attackCount >= m_likelyCount)
            {
                likely.push_back(m_dictionary.getByIndex(i).getKey());
            }

            if (attackCount >= m_possibleCount)
            {
                possible.push_back(m_dictionary.getByIndex(i).getKey());
            }
        }

        theHappenings.addKeyValue("Likely attackers", likely);
        theHappenings.addKeyValue("Possible Attackers", possible);

        std::ofstream goinOut;
        goinOut.open("DenialOfServiceAnalyerResult.txt");

        result.print(goinOut, theHappenings);

        m_TFE++;
        m_TFS++;
    }
}
