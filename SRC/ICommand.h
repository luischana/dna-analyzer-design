#ifndef SRC_ICOMMAND_H
#define SRC_ICOMMAND_H


#include "Params.h"

class ICommand {
public:
    virtual void run(const Params& params) = 0;
};


#endif //SRC_ICOMMAND_H
