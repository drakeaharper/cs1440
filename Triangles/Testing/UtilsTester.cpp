//
// Created by Stephen Clyde on 2/3/17.
//

#include "UtilsTester.h"

#include <iostream>

#include "../Utils.h"

void UtilsTester::testSplit()
{
    std::cout << "Execute UtilsTester::testSplit" << std::endl;

    // Check good cases

    std::string pieces[20];
    std::string lineToSplit = "ABC,DEF,GHI";
    if (split(lineToSplit, ',', pieces, 3)) {
        if (pieces[0] != "ABC" || pieces[1] != "DEF" || pieces[2] != "GHI") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 3) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 3) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    lineToSplit = "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC,D,E";
    if (split(lineToSplit, ',', pieces, 3)) {
        if (pieces[0] != "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC" || pieces[1] != "D" || pieces[2] != "E") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 3) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 3) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    lineToSplit = "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDD";
    if (split(lineToSplit, ',', pieces, 1)) {
        if (pieces[0] != "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDD" || pieces[1] != "D" || pieces[2] != "E") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 1) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 1) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    lineToSplit = "MNO,PQR,STU";
    if (split(lineToSplit, ',', pieces, 0)) {
        if (pieces[0] != "ABCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCDDDDDDDDDD" || pieces[1] != "D" || pieces[2] != "E") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    lineToSplit = "MNO,,STU";
    if (split(lineToSplit, ',', pieces, 3)) {
        if (pieces[0] != "MNO" || pieces[1] != "" || pieces[2] != "STU") {
            std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                      << lineToSplit << "\": pieces not as expected" << std::endl;
            return;
        }
    } else {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }

    // Check bad cases
    lineToSplit = "MNO,PQR,STU";
    if (split(lineToSplit, ',', pieces, 4)) {
        std::cout << "Failure in split(lineToSplit, ',', pieces, 0) for lineToSplit=\""
                  << lineToSplit << "\": result value not as expected" << std::endl;
        return;
    }
}

void UtilsTester::testConvertToDouble()
{
    std::cout << "Execute UtilsTester::testConvertToDouble" << std::endl;

    bool isValid;

    // Check good numbers

    std::string s = "123.4567";
    double result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "  123.4567";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "123.4567  ";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "   123.4567  ";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "-123.4567";
    result = convertStringToDouble(s, &isValid);
    if (result != -123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "1.234567e2";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "12345.67e-2";
    result = convertStringToDouble(s, &isValid);
    if (result != 123.4567 || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "INF";
    result = convertStringToDouble(s, &isValid);
    if (result != std::numeric_limits<double>::infinity() || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "INFINITY";
    result = convertStringToDouble(s, &isValid);
    if (result != std::numeric_limits<double>::infinity() || !isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    // Check bad numbers

    s = "- 123.4567";
    result = convertStringToDouble(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "123.45.67";
    result = convertStringToDouble(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "A123.4567";
    result = convertStringToDouble(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

    s = "123.4567A";
    result = convertStringToDouble(s, &isValid);
    if (result != 0 || isValid) {
        std::cout << "Failure in convertStringToDouble(s, &isValid) for s=\"" << s
                  << "\" result=" << result << " isValid=" << isValid << std::endl;
        return;
    }

}
