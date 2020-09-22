#ifndef SRC_SAVE_H
#define SRC_SAVE_H


#include "ManagementCommand.h"

class Save: public ManagementCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
};


#endif //SRC_SAVE_H
