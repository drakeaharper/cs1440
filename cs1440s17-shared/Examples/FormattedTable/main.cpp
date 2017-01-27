#include <iostream>
#include <fstream>
#include "FormattedTable.h"

void Example1()
{
    std::cout << "Examples of how to use the Table class" << std::endl << std::endl;

    std::cout << "Example 1: Create a table with 3 columns: Name, Age, and Annual Income" << std::endl;
    std::cout << "           Read data from a create 6 rows" << std::endl;

    FormattedTable table(6, 3);

    // Add the column definitions
    table.addColumn(new ColumnDefinition("Name", 20, ColumnDefinition::String));
    table.addColumn(new ColumnDefinition("Age", 6, ColumnDefinition::Integer));
    table.addColumn(new ColumnDefinition("Annual Income", 14, ColumnDefinition::Money));

    std::ifstream inputStream("./Data/Example1.txt");
    while (inputStream.is_open() && !inputStream.eof())
    {
        std::string name;
        int age;
        int salary;
        inputStream >> name >> age >> salary;
        FormattedRow* row = new FormattedRow(&table);
        row->addCell(new FormattedCell(name));
        row->addCell(new FormattedCell(age));
        row->addCell(new FormattedCell(salary));
    }
    inputStream.close();

    std::cout << "           And, then write to an output file" << std::endl << std::endl;
    std::ofstream outputStream("./Data/FormattedExample1.txt");
    table.write(outputStream);

    std::cout << std::endl << "Done" << std::endl << std::endl;
}

void Example2()
{

    std::cout << "Example 2: Create a table with 5 columns: Id, First Name, Last Name, GPA, Total Credits" << std::endl;
    std::cout << "           With 4 rows" << std::endl;

    FormattedTable table(4, 5);

    table.addColumn(new ColumnDefinition("Id", 8, ColumnDefinition::Integer, ColumnDefinition::Center));
    table.addColumn(new ColumnDefinition("First Name", 20, ColumnDefinition::String));
    table.addColumn(new ColumnDefinition("Last Name", 20, ColumnDefinition::String));
    table.addColumn(new ColumnDefinition("GPA", 8, ColumnDefinition::FixedPrecision, ColumnDefinition::Right, 1));
    table.addColumn(new ColumnDefinition("Total Credits", 14, ColumnDefinition::Integer));

    FormattedRow* row = new FormattedRow(&table);
    row->addCell(new FormattedCell((int) 1));
    row->addCell(new FormattedCell("Joe"));
    row->addCell(new FormattedCell("Jones"));
    row->addCell(new FormattedCell((float) 3.84));
    row->addCell(new FormattedCell((int) 84));
    table.addRow(row);

    row = new FormattedRow(&table);
    row->addCell(new FormattedCell((int) 2));
    row->addCell(new FormattedCell("Sue"));
    row->addCell(new FormattedCell("Samuelson"));
    row->addCell(new FormattedCell((float) 3.65));
    row->addCell(new FormattedCell((int) 64));
    table.addRow(row);

    row = new FormattedRow(&table);
    row->addCell(new FormattedCell((int) 3));
    row->addCell(new FormattedCell("Tammy"));
    row->addCell(new FormattedCell("Thompson"));
    row->addCell(new FormattedCell((float) 3.57));
    row->addCell(new FormattedCell((int) 97));
    table.addRow(row);

    row = new FormattedRow(&table);
    row->addCell(new FormattedCell((int) 4));
    row->addCell(new FormattedCell("Charles"));
    row->addCell(new FormattedCell("Carlson"));
    row->addCell(new FormattedCell((float) 3.43));
    row->addCell(new FormattedCell((int) 46));
    table.addRow(row);

    std::cout << "           And, then write to the standard output stream" << std::endl << std::endl;

    table.write(std::cout);

    std::cout << std::endl << "Done" << std::endl << std::endl;
}

int main() {
    Example1();
    Example2();

    return 0;
}

