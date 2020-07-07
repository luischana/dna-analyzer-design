#ifndef SRC_LOADCOMMAND_H
#define SRC_LOADCOMMAND_H


#include <string>
#include "Params.h"

class LoadCommand {
public:
    LoadCommand(const Params& params);
    void run(const Params& params);
};


#endif //SRC_LOADCOMMAND_H
