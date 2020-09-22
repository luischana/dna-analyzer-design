#include "ManagementCommand.h"

#ifndef SRC_RENAME_H
#define SRC_RENAME_H


class ReName: public ManagementCommand {
public:
    ReName(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    void print(DnaHash& dnaHash, IWriter& writer, size_t id);
};


#endif //SRC_RENAME_H