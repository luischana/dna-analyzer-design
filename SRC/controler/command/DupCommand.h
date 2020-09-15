#ifndef SRC_DUPCOMMAND_H
#define SRC_DUPCOMMAND_H


#include "CreationCommand.h"

class DupCommand: public CreationCommand {
public:
    DupCommand(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(DnaHash& dnaHash, IWriter& writer);
};


#endif //SRC_DUPCOMMAND_H
