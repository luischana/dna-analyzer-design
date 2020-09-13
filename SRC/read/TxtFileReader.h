#ifndef SRC_TXTFILEREADER_H
#define SRC_TXTFILEREADER_H


#include <string>
#include "FileRead.h"

class TxtFileReader:public FileRead {
public:
    TxtFileReader(const char* fileName):m_fileName(fileName){}
    /*virtual*/ void read();
    /*virtual*/ const std::string& getStr() const { return m_str; }

private:
    const char* m_fileName;
    std::string m_str;
};


#endif //SRC_TXTFILEREADER_H
