#ifndef SRC_RAWDNAFILEWRITER_H
#define SRC_RAWDNAFILEWRITER_H


#include <string>
#include "FileWriter.h"

class RawdnaFileWriter: public FileWriter {
public:
    RawdnaFileWriter(std::string fileName);
    /*virtual*/ void write(std::string str) const;

private:
    std::string m_fileName;
};


#endif //SRC_RAWDNAFILEWRITER_H
