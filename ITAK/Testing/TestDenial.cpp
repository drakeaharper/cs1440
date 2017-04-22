//
// Created by drake on 4/22/2017.
//

#include "TestDenial.h"

void TestDenial::run()
{
    // create Denial
    DenialOfServiceAnalyzer denial;

    // set member variables
    denial.setLikely(10);
    denial.setPossible(15);
    denial.setTFE(5);
    denial.setTFS(0);

    testLoadFromFile(denial);
}

void TestDenial::testLoadFromFile(DenialOfServiceAnalyzer denial)
{
    std::cout << "Testing loadFromFile().\n";



    // create test file
    std::string fileName = "TestDenialLoad.txt";

    std::ofstream testOUT(fileName);

    testOUT   << "0,119.43.23.54,57414,80" << std::endl
              << "1,141.8.67.235,42975,3389" << std::endl
              << "2,119.43.23.54,62580,80" << std::endl
              << "3,141.8.67.235,42019,3389" << std::endl
              << "2,119.43.23.54,49067,443" << std::endl;

    testOUT.close();

    denial.loadFromFile(fileName);

    Dictionary<std::string, Dictionary<std::string, long>> testD = denial.getDictionary();

    std::vector<std::string> IP {"119.43.23.54", "141.8.67.235", "119.43.23.54", "141.8.67.235", "119.43.23.54"};
    std::vector<std::string> TS_119 {"0", "2"};
    std::vector<std::string> TS_141 {"1", "3"};

    for (unsigned int i = 0; i < testD.getTotalEntries(); i++)
    {
        if (testD.getByIndex(i).getKey() != IP[i])
        {
            std::cout << "Error in IP addresses at index " << i << ". \n";
        }
        /*for (unsigned int j = 0; j < testD.getByIndex(i).getValue().getTotalEntries(); j++)
        {
            if (testD.getByIndex(i).getKey() == "119.43.23.54")
            {
                if (testD.getByIndex(i).getValue().getByIndex(j).getKey() == )
            }
        }*/
    }
}

void TestDenial::testAttackDetection()
{

}
