#include "dup.h"
#include "../AuxiliaryFunc.h"


void Dup::createCommand(const Params& params)
{
    isValid(params);
}

void Dup::isValid(const Params& params)
{
    if (params.getParams().empty() || params.getParams().size() > 2)
    {
        throw std::invalid_argument("INVALID NUM OF ARGUMENTS\n");
    }

    if (!(params.getParams()[0][0] == '@' || params.getParams()[0][0] == '#'))
    {
        throw std::invalid_argument("THE COMMAND DOESN'T KNOW WHICH DNA TO REFER\n");
    }

    if (params.getParams().size() == 2 && params.getParams()[1][0] != '@')
    {
        throw std::invalid_argument("INVALID ARGUMENTS\n");
    }
}

std::string Dup::run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader)
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

    std::string name = dnaHash.getIDMap()[id]->getName();

    if (params.getParams().size() == 1)
    {
        std::stringstream newName;
        newName << name << '_' << dnaHash.getIDMap()[dnaHash.getNameMap()[name]]->getCount();
        name = newName.str();
    }

    else
    {
        name = params.getParams()[1].substr(1);
    }

    DnaSequence dna = dnaHash.getIDMap()[id]->getDnaSequence();

    DnaMetaData* newDna = new DnaMetaData(dna, name, (std::string)"new");
    dnaHash.add(newDna);
    ++Status::s_vecStatus[0];

    std::stringstream string;
    string << dnaHash.getIDMap()[DnaMetaData::getId()]->getId();

    return ("[" + string.str() + "]" + " " + dnaHash.getIDMap()[DnaMetaData::getId()]->getName() + ": " + dnaHash.getIDMap()[DnaMetaData::getId()]->getDnaSequence().castChar() + '\n');
}
