#ifndef SRC_NEW_H
#define SRC_NEW_H


#include "CreationCommand.h"

class New: public CreationCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
};


#endif //SRC_NEW_H
