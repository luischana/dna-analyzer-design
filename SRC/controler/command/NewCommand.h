#ifndef SRC_NEWCOMMAND_H
#define SRC_NEWCOMMAND_H


#include <sstream>
#include "CreationCommand.h"
#include "../params/Params.h"
#include "../../model/DnaHash.h"
#include "../../view/write/IWriter.h"

class NewCommand: public CreationCommand {
public:
    NewCommand(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(DnaHash& dnaHash, IWriter& writer);
};


#endif //SRC_NEWCOMMAND_H
