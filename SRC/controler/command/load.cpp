#include <sstream>
#include "load.h"
#include "../../view/read/RawdnaFileReader.h"


void Load::createCommand(const Params& params)
{
    isValid(params);
}

void Load::isValid(const Params& params)
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

std::string Load::run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader)
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

    DnaMetaData* newDna = new DnaMetaData(fileName.getStr(), name, (std::string)"up to data");
    dnaHash.add(newDna);

    return castStr(dnaHash);
}

std::string Load::castStr(DnaHash& dnaHash)
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
    return ("[" + stringstream.str() + "]" + " " + dnaHash.getIDMap()[DnaMetaData::getId()]->getName() + ": " + dna + '\n');
}
