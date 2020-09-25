#include "ManagementCommand.h"

#ifndef SRC_RENAME_H
#define SRC_RENAME_H


class Rename: public ManagementCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
};


#endif //SRC_RENAME_H
