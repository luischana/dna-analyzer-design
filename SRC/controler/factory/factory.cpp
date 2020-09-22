#include <iostream>
#include "factory.h"
#include "../command/new.h"


std::map<std::string, ICommand*> Factory::s_commands;


ICommand* Factory::create(const Params& params)
{
    try
    {
        s_commands.at(params.getCmdName())->createCommand(params);
        return s_commands.at(params.getCmdName());
    }

    catch(std::out_of_range &ex)
    {

    }
}

void Factory::init()
{
    s_commands.insert(std::pair<std::string, ICommand*>("new", new New));
}

void Factory::release()
{
    delete s_commands.at("new");
}
