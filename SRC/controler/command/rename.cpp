#include "rename.h"
#include "../AuxiliaryFunc.h"


void Rename::createCommand(const Params& params)
{
    isValid(params);
}

void Rename::isValid(const Params& params)
{
    if (params.getParams().size() != 2)
    {
        throw std::invalid_argument("INVALID NUM OF ARGUMENTS\n");
    }

    if (!(params.getParams()[0][0] == '@' || params.getParams()[0][0] == '#'))
    {
        throw std::invalid_argument("THE COMMAND DOESN'T KNOW WHICH DNA TO REFER\n");
    }

    if (params.getParams()[1][0] != '@')
    {
        throw std::invalid_argument("INVALID ARGUMENTS\n");
    }
}

std::string Rename::run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader)
{
    size_t id = 0;

    if (params.getParams()[0][0] == '@')
    {
        if (!dnaHash.isExistName(params.getParams()[0].substr(1)))
        {
            return "name of DNA not found\n";
        }

        id = dnaHash.findIdByName(params.getParams()[0].substr(1));
    }

    else
    {
        id = castToSize(params.getParams()[0].substr(1));

        if (!dnaHash.isExistId(id))
        {
            return "id of DNA not found\n";
        }
    }

    if (dnaHash.isExistName(params.getParams()[1].substr(1)))
    {
        return "the name is already exists\n";
    }

    dnaHash.setName(id, params.getParams()[1].substr(1));

    std::stringstream string;
    string << id;

    return ("[" + string.str() + "] " + dnaHash.getIDMap()[id]->getName() + ": " + dnaHash.getIDMap()[id]->getDnaSequence().castChar() + '\n');
}
