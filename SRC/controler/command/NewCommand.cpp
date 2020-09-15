#include <stdexcept>
#include <iostream>
#include <cstring>
#include "NewCommand.h"


NewCommand::NewCommand(const Params& params)
{
    if (params.getParams().size() < 1 || params.getParams().size() > 2)
    {
        throw std::invalid_argument("INVALID NUMS OF ARGUMENTS");
    }
}

void NewCommand::run(const Params& params, DnaHash& dnaHash, IWriter& writer)
{
    static size_t count = 0;
    std::stringstream stringstream;
    std::string name;
//    std::string tempName;

    if (params.getParams().size() == 1)
    {
        stringstream << "seq" << ++count;
        name = stringstream.str();
    }

    else
    {
        const char* tempName = params.getParams()[1].c_str();

        if (params.getParams()[1][0] == '@')
        {
            name = tempName + 1;
        }

        else
        {
            name = tempName;
        }
    }

    if (dnaHash.getNameMap().find(name) != dnaHash.getNameMap().end())
    {
        std::stringstream name1;
        name1 << name << '_' << dnaHash.getIDMap()[dnaHash.getNameMap()[name]]->getCount();
        name =  name1.str();
    }

    DnaMetaData* newDnaSequence = new DnaMetaData(params.getParams()[0], name, (std::string)"new");
    dnaHash.add(newDnaSequence);
    print(dnaHash, writer);
}

void NewCommand::print(DnaHash& dnaHash, IWriter& writer)
{
    std::stringstream stringstream;

    stringstream << dnaHash.getIDMap()[DnaMetaData::getId()]->getId();

    writer.write("[" + stringstream.str() + "]" + " " + dnaHash.getIDMap()[DnaMetaData::getId()]->getName() + ": " + dnaHash.getIDMap()[DnaMetaData::getId()]->getDnaSequence().castChar() + '\n');
}
