#ifndef SRC_DUP_H
#define SRC_DUP_H


#include "CreationCommand.h"

class Dup: public CreationCommand {
public:
    Dup(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(DnaHash& dnaHash, IWriter& writer);
};


#endif //SRC_DUP_H
