#ifndef SRC_FINDCOMMAND_H
#define SRC_FINDCOMMAND_H


#include "AnalysisCommand.h"

class FindCommand: public AnalysisCommand {
public:
    FindCommand(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(const IWriter& writer, const std::string& string);
};


#endif //SRC_FINDCOMMAND_H
