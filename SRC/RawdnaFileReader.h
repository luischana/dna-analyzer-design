#ifndef SRC_RAWDNAFILEREADER_H
#define SRC_RAWDNAFILEREADER_H


#include "FileRead.h"

class RawdnaFileReader: public FileRead {
public:
    RawdnaFileReader(const char* fileName):m_fileName(fileName){}
    /*virtual*/ void read();
    /*virtual*/ const std::string& getStr() const { return m_str; }

private:
    const char* m_fileName;
    std::string m_str;
};


#endif //SRC_RAWDNAFILEREADER_H
