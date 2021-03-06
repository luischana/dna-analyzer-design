#ifndef SRC_CONCAT_H
#define SRC_CONCAT_H


#include "ManipulationCommand.h"

class Concat: public ManipulationCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
    std::string castStr(DnaHash& dnaHash, size_t id);
};


#endif //SRC_CONCAT_H
