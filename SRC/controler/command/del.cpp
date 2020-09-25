#include "del.h"
#include "../AuxiliaryFunc.h"


void Del::createCommand(const Params& params)
{
    isValid(params);
}

void Del::isValid(const Params& params)
{
    if (params.getParams().size() != 1)
    {
        throw std::invalid_argument("INVALID NUM OF ARGUMENTS\n");
    }

    if (!(params.getParams()[0][0] == '@' || params.getParams()[0][0] == '#'))
    {
        throw std::invalid_argument("THE COMMAND DOESN'T KNOW WHICH DNA TO REFER\n");
    }
}

std::string Del::run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader)
{
    size_t id = 0;

    if (params.getParams()[0][0] == '@')
    {
        if (!dnaHash.isExistName(params.getParams()[0].substr(1)))
        {
            return "name of DNA not found\n";
        }

        id = dnaHash.findIdByName(params.getParams()[0].substr(1));
    }

    else
    {
        id = castToSize(params.getParams()[0].substr(1));

        if (!dnaHash.isExistId(id))
        {
            return "id of DNA not found\n";
        }
    }

    return castStr(dnaHash, writer, reader, id);
}

std::string Del::castStr(DnaHash& dnaHash, IWriter& writer, IReader& reader, size_t id)
{
    std::stringstream string;
    string << id;
    writer.write("Do you really want to delete" + dnaHash.getIDMap()[id]->getName() + ": " + dnaHash.getIDMap()[id]->getDnaSequence().castChar() + "?\n"
                 + "Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'.\n> confirm >>>");

    reader.read();
    std::string input = reader.getStr();

    while(input != "y" && input != "Y" && input != "n" && input != "N")
    {
        writer.write("You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'.\n> confirm >>>");
        reader.read();
        input = reader.getStr();
    }

    if (input == "y" || input == "Y")
    {
        return ("Deleted: [" + string.str() + "] " + dnaHash.getIDMap()[id]->getName() + ": " + dnaHash.getIDMap()[id]->getDnaSequence().castChar() + '\n');
    }

    return "";
}
