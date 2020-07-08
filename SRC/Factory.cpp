#include "Factory.h"
#include "NewCommand.h"
#include "LoadCommand.h"
#include "SaveCommand.h"

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

    if(params.getCmdName() == "save")
    {
        return new SaveCommand(params);
    }

    return NULL;
}