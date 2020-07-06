#include "NewCommand.h"

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
}