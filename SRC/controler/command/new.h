#ifndef SRC_NEW_H
#define SRC_NEW_H


#include <sstream>
#include "CreationCommand.h"
#include "../params/Params.h"
#include "../../model/DnaHash.h"
#include "../../view/write/IWriter.h"

class New: public CreationCommand {
public:
    New(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(DnaHash& dnaHash, IWriter& writer);
};


#endif //SRC_NEW_H
