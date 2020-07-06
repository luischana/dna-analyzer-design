#include "Factory.h"
#include "NewCommand.h"

ICommand* Factory::create(const Params& params)
{
    if(params.getCmdName() == "new")
    {
        return new NewCommand(params);
    }
}