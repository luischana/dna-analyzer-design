#include <sstream>
#include <string>
#include "LenCommand.h"
#include "../AuxiliaryFunc.h"


LenCommand::LenCommand(const Params &params)
{
    if (params.getParams().size() != 1)
    {
        throw std::invalid_argument("invalid num of arguments :(");
    }

    if (params.getParams()[0][0] != '#')
    {
        throw std::invalid_argument("the command doesnt know which DNA to refer :(");
    }
}

void LenCommand::run(const Params &params, DnaHash &dnaHash, IWriter &writer)
{
    std::string dna;
    size_t id = 0;

    std::istringstream(params.getParams()[0].c_str() + 1) >> id;

    if (dnaHash.isexistId(id))
    {
        dna = dnaHash.getIDMap()[id]->getDnaSequence().castChar();
        print(writer, castToString(dna.length()));
    }

    else
    {
        print(writer, castToString(id) + " not found :(");
    }
}

void LenCommand::print(IWriter &writer, std::string str)
{
    writer.write(str + "\n");
}
