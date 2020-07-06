#include <stdexcept>
#include "NewCommand.h"
#include "DnaHash.h"


NewCommand::NewCommand(const Params& params)
{
    if(params.getParams().size() < 1 || params.getParams().size() > 2)
    {
        throw std::invalid_argument("INVALID NUMS OF ARGUMENTS");
    }
}

void NewCommand::run(const Params& params)
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
    DnaHash::getIDMap().insert(std::pair<size_t, DnaMetaData*>(DnaMetaData::getId(), newDnaSequence));
}