#ifndef SRC_SAVECOMMAND_H
#define SRC_SAVECOMMAND_H


#include "ManagementCommand.h"

class SaveCommand: public ManagementCommand {
public:
    SaveCommand(const Params& params);
    void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
};


#endif //SRC_SAVECOMMAND_H
