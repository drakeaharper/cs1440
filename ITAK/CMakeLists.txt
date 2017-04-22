cmake_minimum_required(VERSION 3.6)
project(ITAK)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Utils.cpp Utils.h Dictionary.h KeyValue.h Analyzer.cpp Analyzer.h DenialOfServiceAnalyzer.cpp DenialOfServiceAnalyzer.h PortScanAnalyzer.cpp PortScanAnalyzer.h Configuration.cpp Configuration.h ResultSet.cpp ResultSet.h)
add_executable(ITAK main.cpp ${SOURCE_FILES})

set(SOURCE_FILES Utils.cpp Utils.h Dictionary.h KeyValue.h Testing/TestDenial.cpp Testing/TestDenial.h)
add_executable(TEST Testing/testMain.cpp ${SOURCE_FILES})
