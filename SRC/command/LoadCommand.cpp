#include <stdexcept>
#include <sstream>
#include "LoadCommand.h"
#include "../DNA/DnaMetaData.h"
#include "../DNA/DnaHash.h"
#include "../read/RawdnaFileReader.h"


LoadCommand::LoadCommand(const Params& params)
{
    if(params.getParams().size() < 1 || params.getParams().size() > 2)
    {
        throw std::invalid_argument("INVALID NUMS OF ARGUMENTS");
    }
}

void LoadCommand::run(const Params& params, DnaHash& dnaHash, IWriter& writer)
{
    RawdnaFileReader fileName(params.getParams()[0].c_str());
    fileName.read();

    std::string name;

    if(params.getParams().size() == 1)
    {
       name = params.getParams()[0];
       size_t found = name.find('.');
       name = name.substr(0, found);
    }

    else
    {
        name = params.getParams()[1];
    }

    DnaMetaData* newDnaSequence = new DnaMetaData(fileName.getStr(), name, (std::string)"load");
    dnaHash.add(newDnaSequence);
    print(dnaHash, writer);
}

void LoadCommand::print(DnaHash& dnaHash, IWriter& writer)
{
    std::stringstream stringstream;
    std::string name = dnaHash.getIDMap()[DnaMetaData::getId()]->getDnaSequence().castChar();
    size_t len = name.length();

    if(len > 40)
    {
        name = name.substr(0,31) + "..." + name.substr(len-3,len-1);
    }

    stringstream << dnaHash.getIDMap()[DnaMetaData::getId()]->getId();
    writer.write("[" + stringstream.str() + "]" + " " + dnaHash.getIDMap()[DnaMetaData::getId()]->getName() + ": " + name + '\n');
}
