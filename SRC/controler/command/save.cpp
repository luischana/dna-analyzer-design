#include <sstream>
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


void Save::run(const Params& params, DnaHash& dnaHash, IWriter& writer)
{
    size_t id = 0;
    std::string nameFile;
    std::string nameDna;

    if (params.getParams()[0][0] == '@')
    {
        if (!dnaHash.isexistName(params.getParams()[0].substr(1)))
        {
            writer.write("name of DNA not found\n");
            return;
        }

        id = dnaHash.findIdByName(params.getParams()[0].substr(1));
    }

    else
    {
        id = castToSize(params.getParams()[0].substr(1));

        if (!dnaHash.isexistId(id))
        {
            writer.write("id of DNA not found\n");
            return;
        }
    }

    if (params.getParams().size() == 1)
    {
        nameFile = dnaHash.getIDMap()[id]->getName() + ".rawdna";
    }

    else
    {
        nameFile = params.getParams()[1];
    }

    TxtFileWriter write(nameFile);

    write.write(dnaHash.findInIdMap(id)->getDnaSequence().castChar());
}

