#ifndef SRC_LEN_H
#define SRC_LEN_H


#include "AnalysisCommand.h"

class Len: public AnalysisCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
};


#endif //SRC_LEN_H
