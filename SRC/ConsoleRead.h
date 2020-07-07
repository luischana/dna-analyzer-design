#ifndef SRC_CONSOLEREAD_H
#define SRC_CONSOLEREAD_H


#include "Reader.h"

class ConsoleRead: public Reader {
public:
    ConsoleRead();

    /*virtual*/ std::string read() const { return m_data; }
};


#endif //SRC_CONSOLEREAD_H
