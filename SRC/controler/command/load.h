#ifndef SRC_LOAD_H
#define SRC_LOAD_H


#include <string>
#include "../params/Params.h"
#include "ICommand.h"
#include "CreationCommand.h"

class Load: public CreationCommand {
public:
    Load(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(DnaHash& dnaHash, IWriter& writer);
};


#endif //SRC_LOAD_H
