#ifndef SRC_CONSOLEWRITER_H
#define SRC_CONSOLEWRITER_H


class ConsoleWriter: public IWriter {
public:
    /*virtual*/ void write(std::string str) const;
};


#endif //SRC_CONSOLEWRITER_H
