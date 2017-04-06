//
// Created by drake on 4/5/2017.
//

#include "TestCasesCopyConstructors.h"

void TestCasesCopyConstructors::run()
{
    Dictionary<std::string, std::string> testDictionary;
    // Build a test dictionary
    std::string k1 = "key 1";
    std::string v1 = "value 1";
    testDictionary.addKeyValue(k1, v1);

    std::string k2 = "key 2";
    std::string v2 = "value 2";
    testDictionary.addKeyValue(k2, v2);

    std::string k3 = "key 3";
    std::string v3 = "value 3";
    testDictionary.addKeyValue(k3, v3);

    std::string k4 = "key 4";
    std::string v4 = "value 4";
    testDictionary.addKeyValue(k4, v4);

    std::string k5 = "key 5";
    std::string v5 = "value 5";
    testDictionary.addKeyValue(k5, v5);

    std::cout << "Testing Dictionary copy constructor." << std::endl;
    Dictionary<std::string, std::string> copiedDictionary(testDictionary);
    compareDictionaries(testDictionary, copiedDictionary);

    std::cout << "Testing KeyValue copy constructor." << std::endl;
    KeyValue<std::string, std::string> testKeyValue("test key", "test value");
    KeyValue<std::string, std::string> copiedKV(testKeyValue);
    compareKeyValues(testKeyValue, copiedKV);
}

void TestCasesCopyConstructors::compareDictionaries(Dictionary<std::string, std::string> original, Dictionary<std::string, std::string> copied)
{
    for (unsigned int index = 0; index < copied.getTotalEntries(); index++)
    {
        if (original.getByIndex(index).getKey() != copied.getByIndex(index).getKey())
        {
            std::cout << "Error: copy key differs at index " << index << ". " << std::endl;
        }

        if (original.getByIndex(index).getValue() != copied.getByIndex(index).getValue())
        {
            std::cout << "Error: copy value differs at index " << index << ". " << std::endl;
        }
    }
}

void TestCasesCopyConstructors::compareKeyValues(KeyValue<std::string, std::string> original, KeyValue<std::string, std::string> copied)
{
    if (original.getKey() != copied.getKey())
    {
        std::cout << "Error: copy key is incorrect." << std::endl;
    }

    if (original.getValue() != copied.getValue())
    {
        std::cout << "Error: copy value is incorrect." << std::endl;
    }
}
