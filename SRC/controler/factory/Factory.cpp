#include <iostream>
#include "Factory.h"
#include "controler/command/new.h"
#include "controler/command/load.h"
#include "controler/command/save.h"
#include "controler/command/dup.h"
#include "controler/command/len.h"
#include "controler/command/slice.h"
#include "controler/command/find.h"


ICommand* Factory::create(const Params& params)
{
    if (params.getCmdName() == "new")
    {
        return new New(params);
    }

    if (params.getCmdName() == "load")
    {
        return new Load(params);
    }

    if (params.getCmdName() == "save")
    {
        return new Save(params);
    }

    if (params.getCmdName() == "dup")
    {
        return new Dup(params);
    }

    if (params.getCmdName() == "len")
    {
        return new Len(params);
    }

    if (params.getCmdName() == "slice")
    {
        return new Slice(params);
    }

    if (params.getCmdName() == "find")
    {
        return new Find(params);
    }

    std::cout << "command not found :(" << std::endl;
    return NULL;
}