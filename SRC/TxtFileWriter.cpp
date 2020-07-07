#include <fstream>
#include "TxtFileWriter.h"

void TxtFileWriter::write(std::string str) const
{
    std::ofstream myFile;
    myFile.open(str.c_str());
    myFile << str;
    myFile.close();
}