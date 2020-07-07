#ifndef SRC_DNAHASH_H
#define SRC_DNAHASH_H


#include <map>
#include <string>
#include "DnaMetaData.h"

class DnaHash {
public:
    void add(DnaMetaData* dna);
    std::map<std::string, size_t>& getNameMap() { return m_nameMap; }
    std::map<size_t, DnaMetaData*>& getIDMap() { return m_IDMap; }

private:
    std::map<std::string, size_t> m_nameMap;
    std::map<size_t, DnaMetaData*> m_IDMap;
};


#endif //SRC_DNAHASH_H
