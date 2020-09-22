#include <sstream>
#include "load.h"
#include "../../model/DnaMetaData.h"
#include "../../view/read/RawdnaFileReader.h"


Load::Load(const Params& params)
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

void Load::run(const Params& params, DnaHash& dnaHash, IWriter& writer)
{
    RawdnaFileReader fileName(params.getParams()[0].c_str());
    fileName.read();

    std::string name;

    if (params.getParams().size() == 1)
    {
       name = params.getParams()[0];
       size_t found = name.find('.');
       name = name.substr(0, found);
    }

    else
    {
        name = params.getParams()[1].substr(1);
    }

    DnaMetaData* newDnaSequence = new DnaMetaData(fileName.getStr(), name, (std::string)"load");
    dnaHash.add(newDnaSequence);
    print(dnaHash, writer);
}

void Load::print(DnaHash& dnaHash, IWriter& writer)
{
    std::stringstream stringstream;
    DnaSequence dnaSequence = dnaHash.getIDMap()[DnaMetaData::getId()]->getDnaSequence();
    size_t len = dnaSequence.lenght();
    std::string dna = dnaSequence.castChar();

    if (len > 40)
    {
        dna = dna.substr(0,31) + "..." + dna.substr(len-3,len-1);
    }

    stringstream << dnaHash.getIDMap()[DnaMetaData::getId()]->getId();
    writer.write("[" + stringstream.str() + "]" + " " + dnaHash.getIDMap()[DnaMetaData::getId()]->getName() + ": " + dna + '\n');
}
