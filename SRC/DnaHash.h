#ifndef SRC_DNAHASH_H
#define SRC_DNAHASH_H


#include <map>
#include <string>
#include "DnaMetaData.h"

class DnaHash {
public:
    static std::map<std::string, size_t>& getNameMap();
    static std::map<size_t, DnaMetaData*>& getIDMap();
};


#endif //SRC_DNAHASH_H
