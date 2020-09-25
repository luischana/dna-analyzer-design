#ifndef SRC_DEL_H
#define SRC_DEL_H


#include "ManagementCommand.h"

class Del: public ManagementCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
    std::string castStr(DnaHash& dnaHash, IWriter& writer, IReader& reader, size_t id);
};


#endif //SRC_DEL_H
