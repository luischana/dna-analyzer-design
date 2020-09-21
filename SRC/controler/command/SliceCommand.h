#ifndef SRC_SLICECOMMAND_H
#define SRC_SLICECOMMAND_H


#include "ManipulationCommand.h"

class SliceCommand: public ManipulationCommand {
public:
    SliceCommand(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(DnaHash& dnaHash, IWriter& writer, size_t id);
};


#endif //SRC_SLICECOMMAND_H
