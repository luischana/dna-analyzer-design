#include <sstream>
#include <string>
#include "LenCommand.h"


LenCommand::LenCommand(const Params &params)
{
    if (params.getParams().size() != 1)
    {
        throw std::invalid_argument("INVALID NUMS OF ARGUMENTS");
    }
}

void LenCommand::run(const Params &params, DnaHash &dnaHash, IWriter &writer)
{
    std::stringstream stringstream;
    std::string dna;
    size_t id = 0;

    if (params.getParams()[0][0] == '#')
    {
        std::istringstream(params.getParams()[0].c_str() + 1) >> id;

        if (id <= dnaHash.getIDMap()[DnaMetaData::getId()]->getId())
        {
            dna = dnaHash.getIDMap()[id]->getDnaSequence().castChar();
            stringstream << dna.length();
            writer.write(stringstream.str() + '\n');
        }

        else
        {
            stringstream << id;
            writer.write(stringstream.str() + " not found :(" + '\n');
        }
    }
}
