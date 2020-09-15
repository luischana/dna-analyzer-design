#include "DnaHash.h"


void DnaHash::add(DnaMetaData* dna)
{
    getNameMap().insert(std::pair<std::string, size_t>(dna->getName(), dna->getId()));
    getIDMap().insert(std::pair<size_t, DnaMetaData*>(dna->getId(), dna));
}