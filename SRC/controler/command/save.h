#ifndef SRC_SAVE_H
#define SRC_SAVE_H


#include "ManagementCommand.h"

class Save: public ManagementCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
};


#endif //SRC_SAVE_H
