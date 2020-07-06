#ifndef SRC_NEWCOMMAND_H
#define SRC_NEWCOMMAND_H


#include <sstream>
#include "CreationCommand.h"
#include "DnaMetaData.h"
#include "Params.h"

class NewCommand: public CreationCommand {
public:
    NewCommand(const Params& params);
    void run(const Params& params);
};


#endif //SRC_NEWCOMMAND_H
