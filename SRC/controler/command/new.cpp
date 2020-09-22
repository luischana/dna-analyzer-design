#include <iostream>
#include "new.h"


void New::createCommand(const Params &params)
{
    isValid(params);
}

void New::isValid(const Params& params)
{
    if (params.getParams().empty() || params.getParams().size() > 2)
    {
        throw std::invalid_argument("INVALID NUMS OF ARGUMENTS\n");
    }

    if (params.getParams().size() == 2 && params.getParams()[1][0] != '@')
    {
        throw std::invalid_argument("INVALID COMMAND\n");
    }
}

void New::run(const Params& params, DnaHash& dnaHash, IWriter& writer)
{
    static size_t count = 0;
    std::stringstream stringstream;
    std::string name;

    if (params.getParams().size() == 1)
    {
        stringstream << "seq" << ++count;
        name = stringstream.str();
    }

    else
    {
        name = params.getParams()[1].substr(1);
    }

    if (dnaHash.isexistName(name))
    {
        std::stringstream name1;
        name1 << name << '_' << dnaHash.getIDMap()[dnaHash.getNameMap()[name]]->getCount();
        name =  name1.str();
    }

    DnaMetaData* newDnaSequence = new DnaMetaData(params.getParams()[0], name, (std::string)"new");
    dnaHash.add(newDnaSequence);
    print(dnaHash, writer);
}

void New::print(DnaHash& dnaHash, IWriter& writer)
{
    std::stringstream stringstream;

    stringstream << dnaHash.getIDMap()[DnaMetaData::getId()]->getId();

    writer.write("[" + stringstream.str() + "]" + " " + dnaHash.getIDMap()[DnaMetaData::getId()]->getName() + ": " + dnaHash.getIDMap()[DnaMetaData::getId()]->getDnaSequence().castChar() + '\n');
}
