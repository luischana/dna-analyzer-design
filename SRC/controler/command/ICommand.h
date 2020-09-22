#ifndef SRC_ICOMMAND_H
#define SRC_ICOMMAND_H


#include "../params/Params.h"
#include "../../model/DnaHash.h"
#include "../../view/write/IWriter.h"

class ICommand {
public:
    virtual void createCommand(const Params& params) = 0;
    virtual void run(const Params& params, DnaHash& dnaHash, IWriter& writer) = 0;
};


#endif //SRC_ICOMMAND_H
