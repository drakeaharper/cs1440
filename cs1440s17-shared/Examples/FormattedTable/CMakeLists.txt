cmake_minimum_required(VERSION 3.6)
project(FormattedTable)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ColumnDefinition.cpp ColumnDefinition.h FormattedRow.cpp FormattedRow.h FormattedCell.cpp FormattedCell.h FormattedTable.cpp FormattedTable.h)
add_executable(FormattedTable ${SOURCE_FILES})