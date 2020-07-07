#ifndef SRC_READER_H
#define SRC_READER_H


#include "IReader.h"

class Reader: public IReader {
    protected:
        std::string m_data;
};


#endif //SRC_READER_H
