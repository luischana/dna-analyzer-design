#include "TxtFileWriter.h"

TxtFileWriter::TxtFileWriter(std::string fileName):m_fileName(fileName){}

void TxtFileWriter::write(std::string str) const
{
    std::ofstream myFile;
    myFile.open(str.c_str());
    myFile << str;
    myFile.close();
}