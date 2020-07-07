#ifndef SRC_CONSOLEREAD_H
#define SRC_CONSOLEREAD_H


#include "FileReader.h"

class ConsoleRead: public FileReader {
public:
    ConsoleRead();

    /*virtual*/ std::string read() const { return m_data; }
};


#endif //SRC_CONSOLEREAD_H
