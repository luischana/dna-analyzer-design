#ifndef SRC_TXTFILEWRITER_H
#define SRC_TXTFILEWRITER_H


#include <string>
#include "FileWriter.h"

class TxtFileWriter: public FileWriter {
public:
    TxtFileWriter(std::string fileName): m_fileName(fileName){}
    /*virtual*/ void write(std::string str) const;

private:
    std::string m_fileName;
};


#endif //SRC_TXTFILEWRITER_H
