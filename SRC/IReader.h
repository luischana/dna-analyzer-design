#ifndef DNA_IREADER_H
#define DNA_IREADER_H

#include <string>

class IReader {
public:
    virtual std::string read() const = 0;
};


#endif //DNA_IREADER_H
