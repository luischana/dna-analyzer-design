#ifndef SRC_COUNT_H
#define SRC_COUNT_H


#include "AnalysisCommand.h"

class Count: public AnalysisCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
};


#endif //SRC_COUNT_H
