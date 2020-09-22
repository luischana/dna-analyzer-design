#include "DnaHash.h"


void DnaHash::add(DnaMetaData* dna)
{
    getNameMap().insert(std::pair<std::string, size_t>(dna->getName(), dna->getId()));
    getIDMap().insert(std::pair<size_t, DnaMetaData*>(dna->getId(), dna));
}

size_t DnaHash::findIdByName(const std::string& name)
{
    return m_nameMap[name];
}

DnaMetaData* DnaHash::findInIdMap(size_t id)
{
    return m_IDMap[id];
}

bool DnaHash::isexistName(const std::string &name)
{
    return m_nameMap.find(name) != m_nameMap.end();
}

bool DnaHash::isexistId(size_t id)
{
    return m_IDMap.find(id) != m_IDMap.end();
}
