//
// This purpose of this program is to illustrate various uses of pointers,
// the address operator and the de-referencing operator.
//

#include <iostream>
#include <iomanip>

// Illustrates that array variables are actually pointers
void Example1()
{
    std::cout << "Example 1" << std::endl << std::endl;

    int someIntArray[4] = {123, 234, 345, 456};

    // Display the address of a variable and the variable's value
    std::cout << "Array " << someIntArray << " (an address) " << std::endl;
    std::cout << "\t[0] contains " << someIntArray[0] << std::endl;
    std::cout << "\t[1] contains " << someIntArray[1] << std::endl;
    std::cout << "\t[2] contains " << someIntArray[2] << std::endl;
    std::cout << "\t[3] contains " << someIntArray[3] << std::endl;
    std::cout << std::endl;
}

// Illustrates the addressing operator
void Example2()
{
    std::cout << "Example 2" << std::endl << std::endl;

    int someInt = 10;
    float someFloat = 2.4;
    double someDouble = 325.23523;
    std::string someString = "Hello World";


    // Display the address of a variable and the variable's value
    std::cout << "Address " << &someInt << " contains " << someInt << std::endl;
    std::cout << "Address " << &someFloat << " contains " << someFloat << std::endl;
    std::cout << "Address " << &someDouble << " contains " << someDouble << std::endl;
    std::cout << "Address " << &someString << " contains " << someString << std::endl;
    std::cout << std::endl;
}

// Illustrates pointers and the de-referencing address
void Example3()
{
    std::cout << "Example 3" << std::endl << std::endl;

    int someInt = 12;
    int* aPointerToSomeInt = &someInt;

    // Display the address of a variable and the variable's value
    std::cout << std::left << std::setw(37) << "someInt" << " = " << someInt << std::endl;
    std::cout << std::left <<std::setw(37) <<"Address of someInt" << " = " << &someInt << std::endl;
    std::cout << std::left <<std::setw(37) <<"aPointerToSomeInt" << " = " << aPointerToSomeInt << std::endl;
    std::cout << std::left <<std::setw(37) <<"Value pointed to by aPointerToSomeInt" << " = " << *aPointerToSomeInt << std::endl;
    std::cout << std::endl;
}

// Illustrates the use of pointers for dynamic allocation
void Example4()
{
    std::cout << "Example 4" << std::endl << std::endl;

    int arraySize;
    std::cout << "How big of an array would you create (must be >2 and < 45)? ";
    std::cin >> arraySize;

    int* someArray = new int[arraySize];

    // Load the array with a sequence of number (the fibonacci series)
    someArray[0] = 1;
    someArray[1] = 1;
    for (int i=2; i<arraySize; i++)
        someArray[i] = someArray[i-1] + someArray[i-2];

    // Display the address of a variable and the variable's value

    std::cout << "someArray contains " << arraySize << " << elements" << std::endl;
    for (int i=0; i<arraySize; i++)
        std::cout << std::setw(6) << "someArray[" << i << "]" << " = " << someArray[i] << std::endl;
    std::cout << std::endl;

    delete [] someArray;
}

// Illustrates the use of an array of pointers
void Example5()
{
    std::cout << "Example 4" << std::endl << std::endl;

    int arraySize;
    std::cout << "How big of an array would you create? ";
    std::cin >> arraySize;

    std::string** myStrings = new std::string*[arraySize];

    // Load the array with user input
    for (int i=0; i<arraySize; i++)
    {
        std::string userInput;
        std::cout << "Enter string #" << i << ": ";
        std::cin >> userInput;

        // Dynamically allocate a new string that is a copy of the user input
        myStrings[i] = new std::string(userInput);
    }

    // Display the address of a variable and the variable's value

    std::cout << std::endl;
    std::cout << "myStrings contains " << arraySize << " << elements" << std::endl;
    for (int i=0; i<arraySize; i++)
        std::cout << std::setw(6) << "myArray[" << i << "]" << " = " << *myStrings[i] << std::endl;
    std::cout << std::endl;

    // deallocate all dynamically allocated memory
    for (int i=0; i<arraySize; i++)
        delete myStrings[i];

    delete [] myStrings;
}

int main() {
    Example1();
    Example2();
    Example3();
    Example4();
    Example5();
    return 0;
}