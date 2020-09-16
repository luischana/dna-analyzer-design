#ifndef SRC_LENCOMMAND_H
#define SRC_LENCOMMAND_H


#include "AnalysisCommand.h"

class LenCommand: public AnalysisCommand {
public:
    LenCommand(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
};


#endif //SRC_LENCOMMAND_H
