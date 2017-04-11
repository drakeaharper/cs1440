#include <iostream>
#include <fstream>
#include <string>

#include "Dictionary.h"
#include "Utils.h"

int main()
{
    Dictionary<std::string, KeyValue<std::string, KeyValue<std::string, std::string>>> baseDictionary;
    Utils lyndsee;
    std::string fileName = "SampleData.csv";
    std::ifstream fileIn;
    fileIn.open(fileName);

    if (!fileIn)
    {
        std::cout << "File not opened." << std::endl;
    }

    lyndsee.buildDictionary(baseDictionary, fileIn);

    // ghetto test Utils::buildDictionary() because I can't get the tester config to work
    std::ofstream out("testBuilder.txt");

    for (unsigned int index = 0; index < baseDictionary.getTotalEntries(); index++)
    {
        out << baseDictionary.getByIndex(index).getKey() << ", "
                << baseDictionary.getByIndex(index).getValue().getKey() << ", "
                << baseDictionary.getByIndex(index).getValue().getValue().getKey() << ", "
                << baseDictionary.getByIndex(index).getValue().getValue().getValue() << std::endl;
    }

    return 0;
}