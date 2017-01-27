//
// This program illustrates the use of program arguments.
//
//  argc    the number of arguments (always >= 1)
//  argc    an array of arguments as c-style strings (char*).
//          arg[0] is always the full path of the file being executed.
//
#include <iostream>

int main(int argc, char* argv[]) {
    
    for (int i=0; i<argc; i++)
        std::cout << i << "\t" << argv[i] << std::endl;
    return 0;
}