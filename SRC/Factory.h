#ifndef SRC_FACTORY_H
#define SRC_FACTORY_H


#include "Params.h"
#include "ICommand.h"


class Factory {
public:
    static ICommand* create(const Params& params);
};


#endif //SRC_FACTORY_H
