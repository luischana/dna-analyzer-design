#ifndef SRC_REPLACE_H
#define SRC_REPLACE_H


#include "ManipulationCommand.h"

class Replace: public ManipulationCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
    std::string castStr(DnaHash& dnaHash, size_t id);
};


#endif //SRC_REPLACE_H
