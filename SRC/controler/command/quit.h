#ifndef SRC_QUIT_H
#define SRC_QUIT_H


#include "ControlCommand.h"

class Quit: public ControlCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
};


#endif //SRC_QUIT_H
