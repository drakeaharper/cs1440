#include "Comparer.h"

int main(int argc, char* argv[])
{
    // Declare (and create) a comparer object
    Comparer comparer;

    // Have the comparer load all the input files and then do the comparison,
    // which creates the output file
    if (comparer.load(argc, argv)==0)
        comparer.compare();

    // hello world
}