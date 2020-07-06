#include "DnaHash.h"

std::map<std::string, size_t> &DnaHash::getNameMap(){
    static std::map<std::string, size_t> nameMap;
    return nameMap;
}

std::map<size_t, DnaMetaData*> &DnaHash::getIDMap(){
    static std::map<size_t, DnaMetaData*> IDMap;
    return IDMap;
}
