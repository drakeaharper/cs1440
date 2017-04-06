//
// Created by drake on 4/5/2017.
//

#include "UserInterface.h"

void UserInterface::run()
{
    printCommands(dictionaryCreated);
    std::cout << "Enter a command:";
    std::cin >> input;
    std::cout << std::endl;

    while (keepGoing)
    {
        if (!dictionaryCreated)
        {
            // switch statment for no current dictionary
            switch (input)
            {
                case 'C':
                    myDictionary = new Dictionary<std::string, std::string>();
                    std::cout << "Dictionary created!" << std::endl;
                    dictionaryCreated = true;
                    d = dNext;
                    dNext++;
                    break;

                case 'N':
                    std::cout << "Enter desired size of dictionary: " << std::endl;
                    x = getNumberInput("Enter desired size of dictionary: ", 1, 1000000);
                    myDictionary = new Dictionary<std::string, std::string>(x);
                    std::cout << "Dictionary created with size " << x << "." << std::endl;
                    dictionaryCreated = true;
                    d = dNext;
                    dNext++;
                    break;

                    /*case 'M':
                    std::cout << "Dictionary range 0 - " << dNext - 1 << std::endl;
                        std::cout << "Enter index of dictionary: " << std::endl;
                        std::cin >> d;
                    std::cout << "Moved to dictionary at pos " << d << "." << std::endl;
                        break;*/

                case 'D':
                    std::cout << "Function currently not working." << std::endl;
                    dictionaryCreated = false;
                    break;

                case 'F':
                    std::cout << "Function currently not working." << std::endl;
                    break;

                case 'E':
                    keepGoing = false;
                    break;

                default:
                    std::cout << "Unrecognized input." << std::endl;
                    break;
            }
        }
        else if (dictionaryCreated)
        {
            std::string toFind;
            unsigned int rPosition = 0;
            unsigned int position = 0;
            std::string toRemove;
            std::string fileName;
            std::string key;
            std::string value;

            // switch statement for dictionary created
            switch (input)
            {
                case 'A':
                    try
                    {
                        key = getStringInput("Enter Key: ");
                        value = getStringInput("Enter value: ");
                        myDictionary->addKeyValue(key, value);
                    }
                    catch (std::domain_error err)
                    {
                        std::cout << err.what();
                    }
                    break;

                case 'R':
                    try
                    {
                        toFind = getStringInput("Enter key to be removed: ");
                        myDictionary->removeByKey(toFind);
                    }
                    catch (std::domain_error err)
                    {
                        std::cout << err.what();
                    }
                    break;

                case 'T':
                    rPosition = getNumberInput("Enter position to remove: ", 0, myDictionary->getTotalEntries() - 1);

                    if ( position > 0 && position < myDictionary->getTotalEntries())
                    {
                        myDictionary->removeByIndex(rPosition);
                    }
                    else
                    {
                        std::cout << "Invalid position entered.\nTry Again." << std::endl << std::endl;
                    }
                    break;

                case 'K':
                    try
                    {
                        toFind = getStringInput("Enter key to be found: ");
                        printKeyValue(myDictionary->getByKey(toFind));
                    }
                    catch (std::domain_error err)
                    {
                        std::cout << err.what() << std::endl;
                    }
                    break;

                case 'I':
                    position = getNumberInput("Enter position to look up: ", 0, myDictionary->getTotalEntries() - 1);
                    if ( position >= 0 && position <= myDictionary->getTotalEntries() - 1)
                    {
                        printKeyValue(myDictionary->getByIndex(position));
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
                    std::cin.ignore();
                    if (input == 'k')
                    {
                        try
                        {
                            toFind = getStringInput("Enter key to be printed: ");
                            printKeyValue(myDictionary->getByKey(toFind));
                        }
                        catch (std::domain_error err)
                        {
                            std::cout << err.what() << std::endl;
                        }
                    }
                    else if (input == 'i')
                    {
                        position = getNumberInput("Enter key to be printed: ", 0, myDictionary->getTotalEntries());

                        if ( position >= 0 && position <= myDictionary->getTotalEntries() - 1)
                        {
                            printKeyValue(myDictionary->getByIndex(position));
                        }
                        else
                        {
                            std::cout << "Invalid position entered.\nTry Again." << std::endl << std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "Unrecognized input." << std::endl;
                    }
                    break;

                case 'P':
                    printDictionary(*myDictionary, std::cout, true);
                    break;

                case 'S':
                    fileName = getStringInput("Enter the name of the save file: ");
                    printToFile(*myDictionary, fileName);
                    std::cout << "File saved under: " << fileName << std::endl;
                    break;

                case 'X':
                    dictionaryCreated = false;
                    std::cout << "Exiting dictionary." << std::endl;
                    break;

                default:
                    std::cout << "Unrecognized input." << std::endl;
                    break;
            }
        }

        if (keepGoing)
        {
            printCommands(dictionaryCreated);
            std::cout << "Enter a command." << std::endl;
            std::cin >> input;
            std::cin.ignore();
            std::cout << std::endl;
        }
    }
}

void UserInterface::printCommands(bool created)
{
    std::cout << std::endl;

    std::cout << "Program commands: " << std::endl;

    if (!created)
    {
        std::cout << "C - Create new default dictionary." << std::endl
                  << "N - Create new dictionary with specified size." << std::endl
                  //<< "M - Move to created dictionary." << std::endl
                  << "D - Delete a dictionary." << std::endl
                  << "F - Create dictionary from file." << std::endl
                  << "E - End program." << std::endl;
    }
    else
    {
        std::cout << "A - Add key / value to dictionary." << std::endl
                  << "R - Remove key / value by key." << std::endl
                  << "T - Remove key / value by index." << std::endl
                  << "K - Look up by key." << std::endl
                  << "I - Look up by index." << std::endl
                  << "1 - Print single key / value." << std::endl
                  << "P - Print dictionary to screen." << std::endl
                  << "S - Save dictionary to file." << std::endl
                  << "X - Exit dictionary." << std::endl;
    }

    std::cout << std::endl;
}

void UserInterface::printKeyValue(KeyValue<std::string, std::string> KV)
{
    std::cout << "Key: " << KV.getKey() << std::endl;
    std::cout << "Value: " << KV.getValue() << std::endl;
    std::cout << std::endl;
}

void UserInterface::printToFile(Dictionary<std::string, std::string> toPrint, std::string fileName)
{
    std::ofstream out;
    out.open(fileName);
    printDictionary(toPrint, out, false);
}

void UserInterface::printDictionary(Dictionary<std::string, std::string> toPrint, std::ostream& out, bool toScreen)
{
    KeyValue<std::string, std::string> temp;
    std::string dictionaryName;
    std::cout << "Enter dictionary name: ";
    if (!toScreen)
    {
        std::cin >> dictionaryName;
    }
    out << std::endl;

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

std::string UserInterface::getStringInput(std::string prompt)
{
    std::string userInput;

    std::cout << prompt
              << std::endl;
    std::getline(std::cin, userInput);

    return userInput;
}

int UserInterface::getNumberInput(std::string prompt, int rangeMin, int rangeMax)
{
    int result = -1;
    bool gotValidInput;
    std::string userInput;

    do {
        std::cout << std::endl;
        std::cout << prompt << " ("
                  << rangeMin << " - "
                  << rangeMax << "): "<< std::endl;
        std::getline(std::cin, userInput, '\n');
        if (userInput == "")
        {
            gotValidInput = true;
        } else
        {
            result = std::stoi(userInput);
            gotValidInput = (rangeMin <= result && result <= rangeMax);
        }
    } while (!gotValidInput);
    return result;
}
