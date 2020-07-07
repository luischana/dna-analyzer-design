#include "Factory.h"
#include "NewCommand.h"
#include "LoadCommand.h"

ICommand* Factory::create(const Params& params)
{
    if(params.getCmdName() == "new")
    {
        return new NewCommand(params);
    }

    if(params.getCmdName() == "load")
    {
        return new LoadCommand(params);
    }
    return NULL;
}