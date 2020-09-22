#include "reName.h"
#include "../AuxiliaryFunc.h"


void ReName::createCommand(const Params &params)
{
    isValid(params);
}

void ReName::isValid(const Params& params)
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

void ReName::run(const Params &params, DnaHash &dnaHash, IWriter &writer)
{
    size_t id = 0;

    if (params.getParams()[0][0] == '@')
    {
        if (!dnaHash.isExistName(params.getParams()[0].substr(1)))
        {
            writer.write("name of DNA not found\n");
            return;
        }

        id = dnaHash.findIdByName(params.getParams()[0].substr(1));
    }

    else
    {
        id = castToSize(params.getParams()[0].substr(1));

        if (!dnaHash.isExistId(id))
        {
            writer.write("id of DNA not found\n");
            return;
        }
    }

    if (dnaHash.isExistName(params.getParams()[1].substr(1)))
    {
        writer.write("the name is already exists\n");
        return;
    }

    dnaHash.setName(id, params.getParams()[1].substr(1));
    print(dnaHash, writer, id);
}

void ReName::print(DnaHash &dnaHash, IWriter &writer, size_t id)
{
    std::stringstream stringstream;

    stringstream << id;

    writer.write("[" + stringstream.str() + "] " + dnaHash.getIDMap()[id]->getName() + ": " + dnaHash.getIDMap()[id]->getDnaSequence().castChar() + '\n');
}
