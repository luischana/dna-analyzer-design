#include <stdexcept>
#include <iostream>
#include "NewCommand.h"
#include "DnaHash.h"
#include "IWriter.h"


NewCommand::NewCommand(const Params& params)
{
    if(params.getParams().size() < 1 || params.getParams().size() > 2)
    {
        throw std::invalid_argument("INVALID NUMS OF ARGUMENTS");
    }
}

void NewCommand::run(const Params& params, DnaHash& dnaHash, IWriter& writer)
{
    static size_t count = 0;
    std::stringstream stringstream;
    std::string name;

    if(params.getParams().size() == 1)
    {
        stringstream << "seq" << ++count;
        name = stringstream.str();
    }

    else
    {
        name = params.getParams()[1];
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
