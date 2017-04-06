cmake_minimum_required(VERSION 3.6)
project(Generics)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Dictionary.h KeyValue.h UserInterface.cpp UserInterface.h)
add_executable(MultiDictionary main.cpp ${SOURCE_FILES})

set(TEST_FILES Testing/testMain.cpp Testing/TestCasesString.cpp Testing/TestCasesString.h Testing/TestCasesInt.cpp Testing/TestCasesInt.h Testing/TestCasesStringPointer.cpp Testing/TestCasesStringPointer.h)
add_executable(Testing Testing/testMain.cpp ${SOURCE_FILES}  ${TEST_FILES})

add_executable(SingleDictionary mainTwo.cpp ${SOURCE_FILES})