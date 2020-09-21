#include <iostream>
#include "Factory.h"
#include "../command/NewCommand.h"
#include "../command/LoadCommand.h"
#include "../command/SaveCommand.h"
#include "../command/DupCommand.h"
#include "../command/LenCommand.h"
#include "../command/SliceCommand.h"


ICommand* Factory::create(const Params& params)
{
    if (params.getCmdName() == "new")
    {
        return new NewCommand(params);
    }

    if (params.getCmdName() == "load")
    {
        return new LoadCommand(params);
    }

    if (params.getCmdName() == "save")
    {
        return new SaveCommand(params);
    }

    if (params.getCmdName() == "dup")
    {
        return new DupCommand(params);
    }

    if (params.getCmdName() == "len")
    {
        return new LenCommand(params);
    }

    if (params.getCmdName() == "slice")
    {
        return new SliceCommand(params);
    }

    std::cout << "command not found :(" << std::endl;
    return NULL;
}