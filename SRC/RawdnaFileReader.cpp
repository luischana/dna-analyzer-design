#include <iostream>
#include <fstream>
#include "RawdnaFileReader.h"

RawdnaFileReader::RawdnaFileReader(std::string fileName)
{
    std::ifstream myFile;
    myFile.open(fileName.c_str(), std::ios::in);

    if(myFile.is_open())
    {
        getline(myFile, m_data);
        myFile.close();
    }

    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
}