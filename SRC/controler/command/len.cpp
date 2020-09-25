#include "len.h"
#include "../AuxiliaryFunc.h"


void Len::createCommand(const Params& params)
{
    isValid(params);
}

void Len::isValid(const Params& params)
{
    if (params.getParams().size() != 1)
    {
        throw std::invalid_argument("INVALID NUM OF ARGUMENTS\n");
    }

    if (params.getParams()[0][0] != '#')
    {
        throw std::invalid_argument("THE COMMAND DOESN'T KNOW WHICH DNA TO REFER\n");
    }
}

std::string Len::run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader)
{
    size_t id = 0;
    std::istringstream(params.getParams()[0].c_str() + 1) >> id;

    std::string dna;

    if (dnaHash.isExistId(id))
    {
        dna = dnaHash.getIDMap()[id]->getDnaSequence().castChar();
        return (castToString(dna.length()) + "\n");
    }

    else
    {
        return (castToString(id) + " not found\n");
    }
}
