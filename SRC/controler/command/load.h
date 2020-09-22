#ifndef SRC_LOAD_H
#define SRC_LOAD_H


#include <string>
#include "../params/Params.h"
#include "ICommand.h"
#include "CreationCommand.h"

class Load: public CreationCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(DnaHash& dnaHash, IWriter& writer);
};


#endif //SRC_LOAD_H
