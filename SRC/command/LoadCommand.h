#ifndef SRC_LOADCOMMAND_H
#define SRC_LOADCOMMAND_H


#include <string>
#include "../params/Params.h"
#include "ICommand.h"
#include "CreationCommand.h"

class LoadCommand:public CreationCommand {
public:
    LoadCommand(const Params& params);
    void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(DnaHash& dnaHash, IWriter& writer);
};


#endif //SRC_LOADCOMMAND_H
