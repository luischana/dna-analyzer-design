#include "RawdnaFileWriter.h"

RawdnaFileWriter::RawdnaFileWriter(std::string fileName):m_fileName(fileName){}

void RawdnaFileWriter::write(std::string str) const
{
    std::ofstream myFile;
    myFile.open(str.c_str());
    myFile << str;
    myFile.close();
}