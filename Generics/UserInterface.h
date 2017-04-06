//
// Created by drake on 4/5/2017.
//

#ifndef GENERICS_USERINTERFACE_H
#define GENERICS_USERINTERFACE_H

#include <iostream>
#include <string>
#include <fstream>

#include "Dictionary.h"

class UserInterface
{
private:
    bool keepGoing = true;
    char input;
    std::string inputString;
    bool dictionaryCreated = false;
    Dictionary<std::string, std::string>* myDictionary;

    int x;
    unsigned int d = 0;
    unsigned int dNext = 0;

public:
    void run();
    void printCommands(bool created);
    void printKeyValue(KeyValue<std::string, std::string> KV);
    void printToFile(Dictionary<std::string, std::string> toPrint, std::string);
    void printDictionary(Dictionary<std::string, std::string> toPrint, std::ostream& out, bool toScreen);
    int getNumberInput(std::string prompt, int rangeMin, int rangeMax);
    std::string getStringInput(std::string prompt);

};


#endif //GENERICS_USERINTERFACE_H
