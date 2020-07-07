#include <stdexcept>
#include <sstream>
#include <iostream>
#include "LoadCommand.h"
#include "DnaMetaData.h"
#include "DnaHash.h"
#include "RawdnaFileReader.h"

LoadCommand::LoadCommand(const Params& params)
{
    if(params.getParams().size() < 1 || params.getParams().size() > 2)
    {
        throw std::invalid_argument("INVALID NUMS OF ARGUMENTS");
    }
}

void LoadCommand::run(const Params& params)
{
    RawdnaFileReader fileName(params.getParams()[0]);

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

    DnaMetaData* newDnaSequence = new DnaMetaData(fileName.read(), name, (std::string)"load");
    DnaHash::getIDMap().insert(std::pair<size_t, DnaMetaData*>(DnaMetaData::getId(), newDnaSequence));

    if(params.getParams()[0].length() > 40)
    {
        std::cout << params.getParams()[0].substr(0, 32);
        std::cout << "...";
        std::cout << params.getParams()[0].substr(params.getParams()[0].length()-3,3) << std::endl;
    }

    else
    {
        std::cout << params.getParams()[0] << std::endl;
    }

    std::cout << params.getParams()[1] << std::endl;
    std::cout << params.getParams()[2] << std::endl;
}
