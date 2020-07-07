#ifndef SRC_RAWDNAFILEREADER_H
#define SRC_RAWDNAFILEREADER_H


#include "FileRead.h"

class RawdnaFileReader: public FileRead {
public:
    RawdnaFileReader(std::string fileName);

    /*virtual*/ std::string read() const { return m_data; }
};


#endif //SRC_RAWDNAFILEREADER_H
