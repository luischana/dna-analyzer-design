#ifndef SRC_LOAD_H
#define SRC_LOAD_H


#include "CreationCommand.h"

class Load: public CreationCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
    std::string castStr(DnaHash& dnaHash);
};


#endif //SRC_LOAD_H
