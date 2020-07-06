#ifndef SRC_NEWCOMMAND_H
#define SRC_NEWCOMMAND_H


#include <stdexcept>
#include <sstream>
#include "CreationCommand.h"
#include "DnaMetaData.h"
#include "Params.h"

class NewCommand: public CreationCommand {
public:
    NewCommand(const Params& params);
    void run(const Params& params);
};


inline NewCommand::NewCommand(const Params& params)
{
    if(params.getParams().size() < 1 || params.getParams().size() > 2)
    {
        throw std::invalid_argument("invalid nums of arguments");
    }
}


#endif //SRC_NEWCOMMAND_H
