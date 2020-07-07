#include <iostream>
#include "ConsoleRead.h"

ConsoleRead::ConsoleRead()
{
    std::cout << "> cmd >>>";
    std::getline(std::cin, m_data, '\n');
}