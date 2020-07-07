#include <iostream>
#include <fstream>
#include "TxtFileReader.h"


void TxtFileReader::read()
{
    std::ifstream myFile;
    myFile.open(m_fileName);

    if(myFile.is_open())
    {
        getline(myFile, m_str);
        myFile.close();
    }

    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
}