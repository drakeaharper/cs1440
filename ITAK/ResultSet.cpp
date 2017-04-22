//
// Created by drake on 4/15/2017.
//

#include "ResultSet.h"

void ResultSet::print(std::ostream& out, Dictionary<std::string, std::vector<std::string>> output)
{
    // print level 1 key
    for (unsigned int outer = 0; outer < output.getTotalEntries(); outer++)
    {
        out << output.getByIndex(outer).getKey() << " " << std::endl;

        // print vector
        for (unsigned int inner = 0; inner < output.getByIndex(outer).getValue().size(); outer++)
        {
            out << output.getByIndex(outer).getValue()[inner] << " " << std::endl;
        }
    }
}