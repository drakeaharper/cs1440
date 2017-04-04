//
// Created by drake on 3/29/2017.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Dictionary.h"

void printCommands();
void printKeyValue(KeyValue<std::string, std::string> KV);
void printToFile(Dictionary<std::string, std::string> toPrint, std::string);
void printDictionary(Dictionary<std::string, std::string> toPrint, std::ostream& out);

int main()
{
    bool keepGoing = true;
    char input;
    Dictionary <std::string, std::string>myDictionary;

    printCommands();
    std::cout << "Enter a command." << std::endl;
    std::cin >> input;
    std::cout << std::endl;

    while (keepGoing)
    {
        std::string toFind;
        unsigned int rPosition = 0;
        unsigned int position = 0;
        std::string toRemove;
        std::string fileName;
        std::string key;
        std::string value;

        switch (input)
        {
            case 'A':
                std::cout << "Enter key: ";
                std::cin >> key;
                std::cout << "Enter value: ";
                std::cin >> value;
                try
                {
                    myDictionary.addKeyValue(key, value);
                }
                catch (std::domain_error err)
                {
                    std::cout << err.what();
                }


                break;

            case 'R':
                std::cout << "Enter key to be removed: ";
                std::cin >> toRemove;
                myDictionary.removeByKey(toRemove);
                break;

            case 'T':
                std::cout << "Enter position to be removed: ";
                std::cin >> rPosition;
                myDictionary.removeByIndex(rPosition);
                break;

            case 'K':
                std::cout << "Enter key to be found: ";
                std::cin >> toFind;
                printKeyValue(myDictionary.getByKey(toFind));
                break;

            case 'I':
            std::cout << "Index Range is 0 - " << myDictionary.getTotalEntries() - 1 << std::endl;
                std::cout << "Enter position to be found: ";
                std::cin >> position;
                if ( position > 0 && position < myDictionary.getTotalEntries())
                {
                    printKeyValue(myDictionary.getByIndex(position));
                }
                else
                {
                    std::cout << "Invalid position entered.\nTry Again." << std::endl;
                }
                break;

            case '1':
                std::cout << "Print at key (k) or index (i)? " << std::endl;
            std::cout << "Enter k or i: ";
                std::cin >> input;
                if (input == 'k')
                {
                    std::cout << "Enter key to be printed: ";
                    std::cin >> toFind;
                    printKeyValue(myDictionary.getByKey(toFind));
                } else if (input == 'i')
                {
                    std::cout << "Enter position to be printed: ";
                    std::cin >> position;
                    printKeyValue(myDictionary.getByIndex(position));
                } else
                {
                    std::cout << "Unrecognized input." << std::endl;
                }
                break;

            case 'P':
                printDictionary(myDictionary, std::cout);
                break;

            case 'S':
                std::cout << "Enter the name of the save file: ";
                std::cin >> fileName;
                printToFile(myDictionary, fileName);
                std::cout << "File saved under: " << fileName << std::endl;
                break;
            case 'X':
                keepGoing = false;
                break;

            default:
                std::cout << "Unrecognized input." << std::endl;
                break;
        }


        if (keepGoing)
        {
            printCommands();
            std::cout << "Enter a command." << std::endl;
            std::cin >> input;
            std::cout << std::endl;
        }
    }
    return 0;
}

void printCommands()
{
    std::cout << std::endl;

    std::cout << "Program commands: " << std::endl;


    std::cout << "A - Add key / value to dictionary." << std::endl
                  << "R - Remove key / value by key." << std::endl
                  << "T - Remove key / value by index." << std::endl
                  << "K - Look up by key." << std::endl
                  << "I - Look up by index." << std::endl
                  << "1 - Print single key / value." << std::endl
                  << "P - Print dictionary to screen." << std::endl
                  << "S - Save dictionary to file." << std::endl
                  << "X - Exit dictionary." << std::endl;


    std::cout << std::endl;
}

void printKeyValue(KeyValue<std::string, std::string> KV)
{
    std::cout << "Key: " << KV.getKey() << std::endl;
    std::cout << "Value: " << KV.getValue() << std::endl;
    std::cout << std::endl;
}

void printToFile(Dictionary<std::string, std::string> toPrint, std::string fileName)
{
    std::ofstream out;
    out.open(fileName);
    printDictionary(toPrint, out);
}

void printDictionary(Dictionary<std::string, std::string> toPrint, std::ostream& out)
{
    KeyValue<std::string, std::string> temp;
    std::string dictionaryName;
    std::cout << "Enter dictionary name: ";
    std::cin >> dictionaryName;
    out << "***Dictionary***" << std::endl;
    out << "Dictionary: " << dictionaryName << std::endl << std::endl;
    for (unsigned int index = 0; index < toPrint.getTotalEntries(); index++)
    {
        temp = toPrint.getByIndex(index);
        out << "Index value: " << index << std::endl;
        out << "Key: " << temp.getKey() << std::endl;
        out << "Value: " << temp.getValue() << std::endl;
        out << std::endl;
    }
}