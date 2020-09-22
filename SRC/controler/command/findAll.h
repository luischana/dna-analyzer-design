#ifndef SRC_FINDALL_H
#define SRC_FINDALL_H


#include "AnalysisCommand.h"

class FindAll: public AnalysisCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(const IWriter& writer, std::list<size_t> indexFind);
};


#endif //SRC_FINDALL_H
