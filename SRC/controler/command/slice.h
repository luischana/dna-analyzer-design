#ifndef SRC_SLICE_H
#define SRC_SLICE_H


#include "ManipulationCommand.h"

class Slice: public ManipulationCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(DnaHash& dnaHash, IWriter& writer, size_t id);
};


#endif //SRC_SLICE_H
