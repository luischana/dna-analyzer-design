#include <iostream>
#include <fstream>
#include "RawdnaFileReader.h"


void RawdnaFileReader::read()
{
    std::ifstream myFile;
    myFile.open(m_fileName);

    if (myFile.is_open())
    {
        getline(myFile, m_str);
        myFile.close();
    }

    else
    {
        throw std::ios_base::failure("Unable to open file");
    }
}
