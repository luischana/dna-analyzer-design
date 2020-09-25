#ifndef SRC_DUP_H
#define SRC_DUP_H


#include "CreationCommand.h"

class Dup: public CreationCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
};


#endif //SRC_DUP_H
