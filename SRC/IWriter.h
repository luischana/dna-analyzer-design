#ifndef DNA_IWRITER_H
#define DNA_IWRITER_H


#include <string>

class IWriter {
public:
    virtual void write(std::string str) const = 0;
};


#endif //DNA_IWRITER_H
