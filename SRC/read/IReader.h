#ifndef DNA_IREADER_H
#define DNA_IREADER_H

#include <string>

class IReader {
public:
    virtual void read() = 0;
    virtual const std::string& getStr() const  = 0;
};


#endif //DNA_IREADER_H
