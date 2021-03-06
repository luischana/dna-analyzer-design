#include "DnaHash.h"


void DnaHash::add(DnaMetaData* dna)
{
    getNameMap().insert(std::pair<std::string, size_t>(dna->getName(), dna->getId()));
    getIDMap().insert(std::pair<size_t, DnaMetaData*>(dna->getId(), dna));
}

void DnaHash::del(size_t id)
{
    m_nameMap.erase(m_IDMap[id]->getName());
    delete m_IDMap[id];
    m_IDMap[id] = NULL;
    m_IDMap.erase(id);
}

void DnaHash::setName(size_t id, const std::string& name)
{
    m_nameMap.erase(m_IDMap[id]->getName());
    m_nameMap[name] = id;
    m_IDMap[id]->setName(name);
}

size_t DnaHash::findIdByName(const std::string& name)
{
    return m_nameMap[name];
}

DnaMetaData* DnaHash::findInIdMap(size_t id)
{
    return m_IDMap[id];
}

bool DnaHash::isExistName(const std::string &name)
{
    return m_nameMap.find(name) != m_nameMap.end();
}

bool DnaHash::isExistId(size_t id)
{
    return m_IDMap.find(id) != m_IDMap.end();
}
