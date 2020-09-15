#include "ConsoleWriter.h"


#include <string>
#include <iostream>


void ConsoleWriter::write(std::string str) const
{
    std::cout << str << std::endl;
}