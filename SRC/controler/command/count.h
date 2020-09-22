#ifndef SRC_COUNT_H
#define SRC_COUNT_H


#include "AnalysisCommand.h"

class Count: public AnalysisCommand {
public:
    Count(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(const IWriter& writer, const std::string& string);
};


#endif //SRC_COUNT_H
