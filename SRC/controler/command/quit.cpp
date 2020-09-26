#include "quit.h"
#include "../AuxiliaryFunc.h"


void Quit::createCommand(const Params& params)
{
    isValid(params);
}

void Quit::isValid(const Params& params)
{
    if (!params.getParams().empty())
    {
        throw std::invalid_argument("INVALID NUM OF ARGUMENTS\n");
    }
}

std::string Quit::run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader)
{
    writer.write("There are " + castToString(Status::s_vecStatus[1]) + " modified and " + castToString(Status::s_vecStatus[0]) + " new sequences. Are you sure you want to quit?\nPlease confirm by 'y' or 'Y', or cancel by 'n' or 'N'.\n> confirm >>>");
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
        writer.write("Thank you for using Dnalanyzer.\nGoodbye!");
        return "quit";
    }

    return "";
}
