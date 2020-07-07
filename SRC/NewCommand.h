#ifndef SRC_NEWCOMMAND_H
#define SRC_NEWCOMMAND_H


#include <sstream>
#include "CreationCommand.h"
#include "Params.h"
#include "DnaHash.h"
#include "IWriter.h"

class NewCommand: public CreationCommand {
public:
    NewCommand(const Params& params);
    void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(DnaHash& dnaHash, IWriter& writer);
};


#endif //SRC_NEWCOMMAND_H
