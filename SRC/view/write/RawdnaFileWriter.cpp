#include <fstream>
#include <iostream>
#include "RawdnaFileWriter.h"


void RawdnaFileWriter::write(std::string str) const
{
    std::ofstream myFile;
    myFile.open(m_fileName.c_str());

    if (myFile.is_open())
    {
        myFile << str;
        myFile.close();
    }

    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
}