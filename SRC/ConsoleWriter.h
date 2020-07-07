#ifndef SRC_CONSOLEWRITER_H
#define SRC_CONSOLEWRITER_H


#include "IWriter.h"

class ConsoleWriter: public IWriter {
public:
    /*virtual*/ void write(std::string str) const;
};


#endif //SRC_CONSOLEWRITER_H
