#include <sstream>
#include "SaveCommand.h"
#include "../../view/write/TxtFileWriter.h"


SaveCommand::SaveCommand(const Params& params)
{
    if (params.getParams().size() < 1 || params.getParams().size() > 2)
    {
        throw std::invalid_argument("INVALID NUMS OF ARGUMENTS");
    }
}

void SaveCommand::run(const Params& params, DnaHash& dnaHash, IWriter& writer)
{
    std::string name;

    if (params.getParams().size() == 1)
    {
        const char* temp = params.getParams()[0].c_str();

        if (params.getParams()[0][0] == '#')
        {
            size_t id = 0;
            std::istringstream(temp + 1) >> id;

            name = dnaHash.getIDMap()[id]->getName();

            TxtFileWriter write(name + ".rawdna");
            write.write(dnaHash.getIDMap()[dnaHash.getNameMap()[name]]->getDnaSequence().castChar());
        }

        if (params.getParams()[0][0] == '@')
        {
            name = dnaHash.getIDMap()[dnaHash.getNameMap()[temp + 1]]->getName();

            TxtFileWriter write(name + ".rawdna");
            write.write(dnaHash.getIDMap()[dnaHash.getNameMap()[temp + 1]]->getDnaSequence().castChar());
        }
    }

    else
    {
        TxtFileWriter write(params.getParams()[1]);
        write.write(params.getParams()[0]);
    }
}

