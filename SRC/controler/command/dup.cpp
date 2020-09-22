#include <sstream>
#include "dup.h"
#include "../AuxiliaryFunc.h"


void Dup::createCommand(const Params &params)
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

void Dup::run(const Params &params, DnaHash &dnaHash, IWriter &writer)
{
    std::string name;
    std::string dna;
    size_t id = 0;

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

    name = dnaHash.getIDMap()[id]->getName();

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

    std::string dnaSequence;
    dnaSequence = dnaHash.getIDMap()[id]->getDnaSequence().castChar();

    DnaMetaData* newDnaSequence = new DnaMetaData(DnaSequence(dnaSequence), name, (std::string)"dup");
    dnaHash.add(newDnaSequence);
    print(dnaHash, writer);
}

void Dup::print(DnaHash &dnaHash, IWriter &writer)
{
    std::stringstream stringstream;

    stringstream << dnaHash.getIDMap()[DnaMetaData::getId()]->getId();

    writer.write("[" + stringstream.str() + "]" + " " + dnaHash.getIDMap()[DnaMetaData::getId()]->getName() + ": " + dnaHash.getIDMap()[DnaMetaData::getId()]->getDnaSequence().castChar() + '\n');
}
