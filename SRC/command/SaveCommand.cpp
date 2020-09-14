#include <sstream>
#include "SaveCommand.h"
#include "../write/TxtFileWriter.h"


SaveCommand::SaveCommand(const Params& params)
{
    if(params.getParams().size() < 1 || params.getParams().size() > 2)
    {
        throw std::invalid_argument("INVALID NUMS OF ARGUMENTS");
    }
}

void SaveCommand::run(const Params& params, DnaHash& dnaHash, IWriter& writer)
{
    std::string name;

    if(params.getParams().size() == 1)
    {
        //TODO @
        if(params.getParams()[0][0] == '#')
        {
            const char* strId = params.getParams()[0].c_str();
            size_t id = 0;
            std::istringstream(strId + 1) >> id;

            name = dnaHash.getIDMap()[id]->getName();
        }

        else
        {
            name = params.getParams()[0].substr(1, params.getParams()[0].length());
        }
    }

    else
    {
        /*name = params.getParams()[1];
        params.getParams()[0].substr(1, params.getParams()[0].length());*/
    }

    TxtFileWriter write(name + ".rawdna");
    write.write(dnaHash.getIDMap()[dnaHash.getNameMap()[name]]->getDnaSequence().castChar());
}
