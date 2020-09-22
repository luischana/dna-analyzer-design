#ifndef SRC_LEN_H
#define SRC_LEN_H


#include "AnalysisCommand.h"

class Len: public AnalysisCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(IWriter& writer, std::string str);
};


#endif //SRC_LEN_H
