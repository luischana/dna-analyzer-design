#include "save.h"
#include "../../view/write/TxtFileWriter.h"
#include "../AuxiliaryFunc.h"


void Save::createCommand(const Params &params)
{
    isValid(params);
}

void Save::isValid(const Params& params)
{
    if (params.getParams().empty() || params.getParams().size() > 2)
    {
        throw std::invalid_argument("INVALID NUMS OF ARGUMENTS\n");
    }

    if (!(params.getParams()[0][0] == '@' || params.getParams()[0][0] == '#'))
    {
        throw std::invalid_argument("THE COMMAND DOESN'T KNOW WHICH DNA TO REFER\n");
    }
}


std::string Save::run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader)
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

    std::string nameFile;

    if (params.getParams().size() == 1)
    {
        nameFile = dnaHash.getIDMap()[id]->getName() + ".rawdna";
    }

    else
    {
        nameFile = params.getParams()[1];
        size_t found = nameFile.find('.');
        nameFile = nameFile.substr(0, found);
        nameFile += ".rawdna";
    }

    TxtFileWriter write(nameFile);
    write.write(dnaHash.findInIdMap(id)->getDnaSequence().castChar());

    return "";
}
