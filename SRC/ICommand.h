#ifndef SRC_ICOMMAND_H
#define SRC_ICOMMAND_H


#include "Params.h"
#include "DnaHash.h"
#include "IWriter.h"

class ICommand {
public:
    virtual void run(const Params& params, DnaHash& dnaHash, IWriter& writer) = 0;
};


#endif //SRC_ICOMMAND_H
