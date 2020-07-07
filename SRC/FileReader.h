#ifndef SRC_FILEREADER_H
#define SRC_FILEREADER_H


#include "IReader.h"

class FileReader: public IReader {
    protected:
        std::string m_data;
};


#endif //SRC_FILEREADER_H
