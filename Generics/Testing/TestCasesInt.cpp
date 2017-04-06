//
// Created by drake on 4/5/2017.
//

#include "TestCasesInt.h"

void TestCasesInt::run()
{
    Dictionary<int, int> testDictionary;
    // Build a test dictionary
    int k1 = 1;
    int v1 = 2;
    testDictionary.addKeyValue(k1, v1);

    int k2 = 3;
    int v2 = 4;
    testDictionary.addKeyValue(k2, v2);

    int k3 = 5;
    int v3 = 6;
    testDictionary.addKeyValue(k3, v3);

    int k4 = 7;
    int v4 = 8;
    testDictionary.addKeyValue(k4, v4);

    int k5 = 9;
    int v5 = 10;
    testDictionary.addKeyValue(k5, v5);

    std::cout << "Testing Dictionary Class with int data type." << std::endl;
    testGetByKey(testDictionary);
    testGetByIndex(testDictionary);
    testAdd(testDictionary);
    testRemoveByKey(testDictionary);
    testRemoveByIndex(testDictionary);
}

void TestCasesInt::testAdd(Dictionary<int, int>& testDictionary)
{
    std::cout << "Testing add function." << std::endl;

    int t1 = 100;
    int t2 = 101;
    testDictionary.addKeyValue(t1, t2);

    KeyValue<int, int> test = testDictionary.getByIndex(5);

    if (test.getKey() != t1)
    {
        std::cout << "Error adding key \"100\" to dictionary." << std::endl;
    }

    if (test.getValue() != t2)
    {
        std::cout << "Error adding value \"101\" to dictionary" << std::endl;
    }
}

void TestCasesInt::testGetByKey(Dictionary<int, int>& testDictionary)
{
    std::cout << "Testing get by key." << std::endl;

    KeyValue<int, int> test = testDictionary.getByKey(5);

    if (test.getKey() != 5)
    {
        std::cout << "Error getting key at index \"2.\" Expected \"5.\" Got \"" << test.getKey() << ".\"" << std::endl;
    }

    if (test.getValue() != 6)
    {
        std::cout << "Error getting key at index \"2.\" Expected \"6.\" Got \"" << test.getValue() << ".\"" << std::endl;
    }
}

void TestCasesInt::testGetByIndex(Dictionary<int, int>& testDictionary)
{
    std::cout << "Testing get by Index." << std::endl;

    KeyValue<int, int> test = testDictionary.getByIndex(2);

    if (test.getKey() != 5)
    {
        std::cout << "Error getting key at index \"2.\" Expected \"5.\" Got \"" << test.getKey() << ".\"" << std::endl;
    }

    if (test.getValue() != 6)
    {
        std::cout << "Error getting key at index \"2.\" Expected \"6.\" Got \"" << test.getValue() << ".\"" << std::endl;
    }
}

void TestCasesInt::testRemoveByKey(Dictionary<int, int>& testDictionary)
{
    std::cout << "Testing remove by key." << std::endl;

    testDictionary.removeByKey(5);
    KeyValue<int, int> test = testDictionary.getByIndex(2);

    if (test.getKey() == 5)
    {
        std::cout << "Error getting key at index \"2.\" Expected \"7.\" Got \"" << test.getKey() << ".\"" << std::endl;
    }

    if (test.getValue() == 6)
    {
        std::cout << "Error getting key at index \"2.\" Expected \"8.\" Got \"" << test.getValue() << ".\"" << std::endl;
    }
}

void TestCasesInt::testRemoveByIndex(Dictionary<int, int>& testDictionary)
{
    std::cout << "Testing remove by Index." << std::endl;

    testDictionary.removeByIndex(0);
    KeyValue<int, int> test = testDictionary.getByIndex(0);

    if (test.getKey() == 1)
    {
        std::cout << "Error getting key at index \"0.\" Expected \"1.\" Got \"" << test.getKey() << ".\"" << std::endl;
    }

    if (test.getValue() == 2)
    {
        std::cout << "Error getting key at index \"0.\" Expected \"2.\" Got \"" << test.getValue() << ".\"" << std::endl;
    }
}
