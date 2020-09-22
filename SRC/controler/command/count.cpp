#include "count.h"
#include "../AuxiliaryFunc.h"


Count::Count(const Params &params)
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

void Count::run(const Params &params, DnaHash &dnaHash, IWriter &writer)
{
    size_t idDnaOrginal;
    size_t idDnaSub = 0;
    size_t count;

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
        count = dnaHash.findInIdMap(idDnaOrginal)->getDnaSequence().count(dnaHash.findInIdMap(idDnaSub)->getDnaSequence());
    }

    else
    {
        count = dnaHash.findInIdMap(idDnaOrginal)->getDnaSequence().count(params.getParams()[1]);
    }

    print(writer, castToString(count));
}

void Count::print(const IWriter& writer, const std::string& string)
{
    writer.write(string + "\n");
}
