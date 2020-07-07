#ifndef SRC_CONSOLEREAD_H
#define SRC_CONSOLEREAD_H


#include "IReader.h"

class ConsoleRead: public IReader {
public:
    /*virtual*/ void read();
    /*virtual*/ const std::string& getStr() const { return m_str; }

private:
    std::string m_str;
};


#endif //SRC_CONSOLEREAD_H
