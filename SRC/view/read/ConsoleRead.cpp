#include <iostream>
#include "ConsoleRead.h"


void ConsoleRead::read()
{
    std::cout << "> cmd >>>";
    std::getline(std::cin, m_str, '\n');
}