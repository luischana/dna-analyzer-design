#include <sstream>
#include "FindCommand.h"
#include "../AuxiliaryFunc.h"


FindCommand::FindCommand(const Params &params)
{
    if (params.getParams().size() != 2)
    {
        throw std::invalid_argument("INVALID NUM OF ARGUMENTS\n");
    }

    if (!(params.getParams()[0][0] == '@' || params.getParams()[0][0] == '#'))
    {
        throw std::invalid_argument("THE COMMAND DOESN'T KNOW WHICH DNA TO REFER\n");
    }
}

void FindCommand::run(const Params &params, DnaHash &dnaHash, IWriter &writer)
{
    size_t idDnaOrginal;
    size_t idDnaSub = 0;
    size_t indexFind;

    if (params.getParams()[0][0] == '@')
    {
        if (!dnaHash.isexistName(params.getParams()[0].substr(1)))
        {
            writer.write("name of DNA not found\n");
            return;
        }

        idDnaOrginal = dnaHash.findIdByName(params.getParams()[0].substr(1));
    }

    else
    {
        idDnaOrginal = castToSize(params.getParams()[0].substr(1));

        if (!dnaHash.isexistId(idDnaOrginal))
        {
            writer.write("id of DNA not found\n");
            return;
        }
    }

    if (params.getParams()[1][0] == '@')
    {
        if (!dnaHash.isexistName(params.getParams()[1].substr(1)))
        {
            writer.write("name of DNA not found\n");
            return;
        }

        idDnaSub = dnaHash.findIdByName(params.getParams()[0].substr(1));
    }

    else if (params.getParams()[1][0] == '#')
    {
        idDnaSub = castToSize(params.getParams()[1].substr(1));

        if (!dnaHash.isexistId(idDnaSub))
        {
            writer.write("id of DNA not found\n");
            return;
        }
    }

    if (idDnaSub)
    {
        indexFind = dnaHash.findInIdMap(idDnaOrginal)->getDnaSequence().find(dnaHash.findInIdMap(idDnaSub)->getDnaSequence());
    }

    else
    {
        indexFind = dnaHash.findInIdMap(idDnaOrginal)->getDnaSequence().find(params.getParams()[1]);
    }

    if (indexFind == dnaHash.findInIdMap(idDnaOrginal)->getDnaSequence().lenght())
    {
        print(writer, "this subsequence not in sequence");
        return;
    }

    print(writer, castToString(indexFind));
}

void FindCommand::print(const IWriter& writer, const std::string& string)
{
    writer.write(string + "\n");
}
