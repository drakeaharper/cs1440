cmake_minimum_required(VERSION 3.6)
project(Generics)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Dictionary.h KeyValue.h)
add_executable(MultiDictionary main.cpp ${SOURCE_FILES})

set(TEST_FILES Testing/testMain.cpp Testing/KeyValueTester.cpp Testing/KeyValueTester.h)
add_executable(Testing Testing/testMain.cpp ${SOURCE_FILES}  ${TEST_FILES})

set(SOURCE_FILES Dictionary.h KeyValue.h)
add_executable(SingleDictionary mainTwo.cpp ${SOURCE_FILES})