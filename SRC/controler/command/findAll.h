#ifndef SRC_FINDALL_H
#define SRC_FINDALL_H


#include "AnalysisCommand.h"

class FindAll: public AnalysisCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
    std::string castStr(std::list<size_t> indexFind);
};


#endif //SRC_FINDALL_H
