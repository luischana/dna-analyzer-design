#include <sstream>
#include "DupCommand.h"


DupCommand::DupCommand(const Params &params)
{
    if (params.getParams().size() < 1 || params.getParams().size() > 2)
    {
        throw std::invalid_argument("INVALID NUMS OF ARGUMENTS");
    }
}

void DupCommand::run(const Params &params, DnaHash &dnaHash, IWriter &writer)
{
    std::string name;
    size_t id = 0;

    if (params.getParams().size() == 1)
    {
        const char* temp = params.getParams()[0].c_str();

        if (params.getParams()[0][0] == '#')
        {
            std::istringstream(temp + 1) >> id;
            name = dnaHash.getIDMap()[id]->getName();
        }

        if (params.getParams()[0][0] == '@')
        {
            name = dnaHash.getIDMap()[dnaHash.getNameMap()[temp + 1]]->getName();
            id = dnaHash.getNameMap()[temp + 1];
        }

        std::stringstream tempName;
        tempName << name << '_' << dnaHash.getIDMap()[dnaHash.getNameMap()[name]]->getCount();
        name =  tempName.str();
    }

    else
    {
        std::string oldName;
        oldName = params.getParams()[0];

        id = dnaHash.getNameMap()[oldName];
        name = params.getParams()[1].c_str() + 1;
    }

    std::string dna;
    dna = dnaHash.getIDMap()[id]->getDnaSequence().castChar();

    DnaMetaData* newDnaSequence = new DnaMetaData(DnaSequence(dna), name, (std::string)"dup");
    dnaHash.add(newDnaSequence);
    print(dnaHash, writer);
}

void DupCommand::print(DnaHash &dnaHash, IWriter &writer)
{
    std::stringstream stringstream;

    stringstream << dnaHash.getIDMap()[DnaMetaData::getId()]->getId();

    writer.write("[" + stringstream.str() + "]" + " " + dnaHash.getIDMap()[DnaMetaData::getId()]->getName() + ": " + dnaHash.getIDMap()[DnaMetaData::getId()]->getDnaSequence().castChar() + '\n');
}
