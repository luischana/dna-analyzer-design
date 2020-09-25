#ifndef SRC_FIND_H
#define SRC_FIND_H


#include "AnalysisCommand.h"

class Find: public AnalysisCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
};


#endif //SRC_FIND_H
