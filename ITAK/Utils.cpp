//
// Created by drake on 4/11/2017.
//

#include "Utils.h"

void Utils::buildDictionary(Dictionary<std::string, KeyValue<std::string, KeyValue<std::string, std::string>>>& baseDictionary, std::ifstream& in)
{
    unsigned int lineCounter = 0;
    while (lineCounter < 100)
    {
        std::string ss;
        getline(in, ss);


        std::string fields[4];
        int fieldPosition = 0;
        KeyValue<std::string, KeyValue<std::string, std::string>> first;
        KeyValue<std::string, std::string> second;

        for (unsigned int index = 0; index < ss.length() && fieldPosition < 4; index++ )
        {
            if (ss[index] == ',')
            {
                index++;
                fieldPosition++;
            }

            fields[fieldPosition] += ss[index];
        }

        second.setKey(fields[2]);
        second.setValue(fields[3]);
        first.setKey(fields[1]);
        first.setValue(second);
        baseDictionary.addKeyValue(fields[0], first);

        lineCounter++;
    }
}