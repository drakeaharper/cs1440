//
// Created by drake on 4/5/2017.
//

#include "TestCasesStringPointer.h"

void TestCasesStringPointer::run()
{
    Dictionary<std::string*, std::string*> testDictionary;
    // Build a test dictionary
    std::string* k1 = new std::string("key 1");
    std::string* v1 = new std::string("value 1");
    testDictionary.addKeyValue(k1, v1);

    std::string* k2 = new std::string("key 2");
    std::string* v2 = new std::string("value 2");
    testDictionary.addKeyValue(k2, v2);

    std::string* k3 = new std::string("key 3");
    std::string* v3 = new std::string("value 3");
    testDictionary.addKeyValue(k3, v3);

    std::string* k4 = new std::string("key 4");
    std::string* v4 = new std::string("value 4");
    testDictionary.addKeyValue(k4, v4);

    std::string* k5 = new std::string("key 5");
    std::string* v5 = new std::string("value 5");
    testDictionary.addKeyValue(k5, v5);

    std::cout << "Testing Dictionary Class with std::string* type." << std::endl;
    testGetByKey(testDictionary, k3);
    testGetByIndex(testDictionary);
    testAdd(testDictionary);
    testRemoveByKey(testDictionary, k3);
    testRemoveByIndex(testDictionary);
}

void TestCasesStringPointer::testAdd(Dictionary<std::string*, std::string*>& testDictionary)
{
    std::cout << "Testing add function." << std::endl;

    std::string* t1 = new std::string("test key");
    std::string* t2 = new std::string("test value");
    testDictionary.addKeyValue(t1, t2);

    KeyValue<std::string*, std::string*> test = testDictionary.getByIndex(5);

    if (test.getKey() != t1)
    {
        std::cout << "Error adding key \"test key\" to dictionary." << std::endl;
    }

    if (test.getValue() != t2)
    {
        std::cout << "Error adding value \"test value\" to dictionary" << std::endl;
    }
}

void TestCasesStringPointer::testGetByKey(Dictionary<std::string*, std::string*>& testDictionary, std::string* testKey)
{
    std::cout << "Testing get by key." << std::endl;

    KeyValue<std::string*, std::string*> test = testDictionary.getByKey(testKey);

    if (*test.getKey() != "key 3")
    {
        std::cout << "Error getting key at index \"2.\" Expected \"key 3.\" Got \"" << *test.getKey() << ".\"" << std::endl;
    }

    if (*test.getValue() != "value 3")
    {
        std::cout << "Error getting key at index \"2.\" Expected \"value 3.\" Got \"" << *test.getValue() << ".\"" << std::endl;
    }
}

void TestCasesStringPointer::testGetByIndex(Dictionary<std::string*, std::string*>& testDictionary)
{
    std::cout << "Testing get by Index." << std::endl;


    KeyValue<std::string*, std::string*> test = testDictionary.getByIndex(2);

    if (*test.getKey() != "key 3")
    {
        std::cout << "Error getting key at index \"2.\" Expected \"key 3.\" Got \"" << *test.getKey() << ".\"" << std::endl;
    }

    if (*test.getValue() != "value 3")
    {
        std::cout << "Error getting key at index \"2.\" Expected \"value 3.\" Got \"" << *test.getValue() << ".\"" << std::endl;
    }
}

void TestCasesStringPointer::testRemoveByKey(Dictionary<std::string*, std::string*>& testDictionary, std::string* testKey)
{
    std::cout << "Testing remove by key." << std::endl;

    testDictionary.removeByKey(testKey);
    KeyValue<std::string*, std::string*> test = testDictionary.getByIndex(2);

    if (*test.getKey() == "key 3")
    {
        std::cout << "Error getting key at index \"2.\" Expected \"key 4.\" Got \"" << *test.getKey() << ".\"" << std::endl;
    }

    if (*test.getValue() == "value 3")
    {
        std::cout << "Error getting key at index \"2.\" Expected \"value 4.\" Got \"" << *test.getValue() << ".\"" << std::endl;
    }
}

void TestCasesStringPointer::testRemoveByIndex(Dictionary<std::string*, std::string*>& testDictionary)
{
    std::cout << "Testing remove by Index." << std::endl;

    testDictionary.removeByIndex(0);
    KeyValue<std::string*, std::string*> test = testDictionary.getByIndex(0);

    if (*test.getKey() == "key 1")
    {
        std::cout << "Error getting key at index \"0.\" Expected \"key 2.\" Got \"" << *test.getKey() << ".\"" << std::endl;
    }

    if (*test.getValue() == "value 3")
    {
        std::cout << "Error getting key at index \"0.\" Expected \"value 2.\" Got \"" << *test.getValue() << ".\"" << std::endl;
    }
}
