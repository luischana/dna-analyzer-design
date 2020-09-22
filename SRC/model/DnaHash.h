#ifndef SRC_DNAHASH_H
#define SRC_DNAHASH_H


#include <map>
#include <string>
#include "DnaMetaData.h"

class DnaHash {
public:
    void add(DnaMetaData* dna);
    std::map<std::string, size_t>&  getNameMap() { return m_nameMap; }
    std::map<size_t, DnaMetaData*>& getIDMap()   { return m_IDMap; }

    size_t findIdByName(const std::string& name);
    DnaMetaData* findInIdMap(size_t id);

    bool isexistName(const std::string& name);
    bool isexistId(size_t id);

private:
    std::map<std::string, size_t>  m_nameMap;
    std::map<size_t, DnaMetaData*> m_IDMap;
};

#endif //SRC_DNAHASH_H
