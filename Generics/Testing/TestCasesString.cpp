//
// Created by drake on 4/3/2017.
//

#include "TestCasesString.h"


void TestCasesString::run()
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

    std::cout << "Testing Dictionary Class with std::string type." << std::endl;
    testGetByKey(testDictionary);
    testGetByIndex(testDictionary);
    testAdd(testDictionary);
    testRemoveByKey(testDictionary);
    testRemoveByIndex(testDictionary);
}

void TestCasesString::testAdd(Dictionary<std::string, std::string>& testDictionary)
{
    std::cout << "Testing add function." << std::endl;

    std::string t1 = "test key";
    std::string t2 = "test value";
    testDictionary.addKeyValue(t1, t2);

    KeyValue<std::string, std::string> test = testDictionary.getByIndex(5);

    if (test.getKey() != t1)
    {
        std::cout << "Error adding key \"test key\" to dictionary." << std::endl;
    }

    if (test.getValue() != t2)
    {
        std::cout << "Error adding value \"test value\" to dictionary" << std::endl;
    }
}

void TestCasesString::testGetByKey(Dictionary<std::string, std::string>& testDictionary)
{
    std::cout << "Testing get by key." << std::endl;

    KeyValue<std::string, std::string> test = testDictionary.getByKey("key 3");

    if (test.getKey() != "key 3")
    {
        std::cout << "Error getting key at index \"2.\" Expected \"key 3.\" Got \"" << test.getKey() << ".\"" << std::endl;
    }

    if (test.getValue() != "value 3")
    {
        std::cout << "Error getting key at index \"2.\" Expected \"value 3.\" Got \"" << test.getValue() << ".\"" << std::endl;
    }
}

void TestCasesString::testGetByIndex(Dictionary<std::string, std::string>& testDictionary)
{
    std::cout << "Testing get by Index." << std::endl;

    KeyValue<std::string, std::string> test = testDictionary.getByIndex(2);

    if (test.getKey() != "key 3")
    {
        std::cout << "Error getting key at index \"2.\" Expected \"key 3.\" Got \"" << test.getKey() << ".\"" << std::endl;
    }

    if (test.getValue() != "value 3")
    {
        std::cout << "Error getting key at index \"2.\" Expected \"value 3.\" Got \"" << test.getValue() << ".\"" << std::endl;
    }
}

void TestCasesString::testRemoveByKey(Dictionary<std::string, std::string>& testDictionary)
{
    std::cout << "Testing remove by key." << std::endl;

    testDictionary.removeByKey("key 3");
    KeyValue<std::string, std::string> test = testDictionary.getByIndex(2);

    if (test.getKey() == "key 3")
    {
        std::cout << "Error getting key at index \"2.\" Expected \"key 4.\" Got \"" << test.getKey() << ".\"" << std::endl;
    }

    if (test.getValue() == "value 3")
    {
        std::cout << "Error getting key at index \"2.\" Expected \"value 4.\" Got \"" << test.getValue() << ".\"" << std::endl;
    }
}

void TestCasesString::testRemoveByIndex(Dictionary<std::string, std::string>& testDictionary)
{
    std::cout << "Testing remove by Index." << std::endl;

    testDictionary.removeByIndex(0);
    KeyValue<std::string, std::string> test = testDictionary.getByIndex(0);

    if (test.getKey() == "key 1")
    {
        std::cout << "Error getting key at index \"0.\" Expected \"key 2.\" Got \"" << test.getKey() << ".\"" << std::endl;
    }

    if (test.getValue() == "value 3")
    {
        std::cout << "Error getting key at index \"0.\" Expected \"value 2.\" Got \"" << test.getValue() << ".\"" << std::endl;
    }
}
