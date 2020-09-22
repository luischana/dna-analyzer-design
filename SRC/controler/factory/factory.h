#ifndef SRC_FACTORY_H
#define SRC_FACTORY_H


#include "../params/Params.h"
#include "../command/ICommand.h"

class Factory {
public:
    static ICommand* create(const Params& params);
    static void init();
    static void release();

private:
    static std::map<std::string, ICommand*> s_commands;
};


#endif //SRC_FACTORY_H
