#ifndef SRC_FIND_H
#define SRC_FIND_H


#include "AnalysisCommand.h"

class Find: public AnalysisCommand {
public:
    Find(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(const IWriter& writer, const std::string& string);
};


#endif //SRC_FIND_H
