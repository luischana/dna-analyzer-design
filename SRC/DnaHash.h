#ifndef SRC_DNAHASH_H
#define SRC_DNAHASH_H


#include <map>
#include <string>
#include "DnaMetaData.h"

class DnaHash {
private:
    static std::map<std::string, size_t> mapDnaName;
    static std::map<size_t, DnaMetaData*> mapDnaId;
};


#endif //SRC_DNAHASH_H
