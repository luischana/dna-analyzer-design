#include <iostream>
#include "ConsoleRead.h"


void ConsoleRead::read()
{
    std::getline(std::cin, m_str, '\n');
}