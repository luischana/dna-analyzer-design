#ifndef SRC_SLICE_H
#define SRC_SLICE_H


#include "ManipulationCommand.h"

class Slice: public ManipulationCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
    std::string castStr(DnaHash& dnaHash, size_t id);
};


#endif //SRC_SLICE_H
