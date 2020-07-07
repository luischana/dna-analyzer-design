#ifndef SRC_TXTFILEREADER_H
#define SRC_TXTFILEREADER_H


#include <string>
#include "FileRead.h"

class TxtFileReader:public FileRead {
public:
    TxtFileReader(std::string fileName);

    /*virtual*/ std::string read() const { return m_data; }
};


#endif //SRC_TXTFILEREADER_H
