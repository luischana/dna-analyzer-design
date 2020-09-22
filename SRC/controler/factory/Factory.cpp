#include <iostream>
#include "Factory.h"
#include "../command/new.h"
#include "../command/load.h"
#include "../command/save.h"
#include "../command/dup.h"
#include "../command/len.h"
#include "../command/slice.h"
#include "../command/find.h"
#include "../command/count.h"


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

    if (params.getCmdName() == "count")
    {
        return new Count(params);
    }

    std::cout << "command not found :(" << std::endl;
    return NULL;
}