#include <iostream>
#include "factory.h"
#include "../command/new.h"
#include "../command/load.h"
#include "../command/save.h"
#include "../command/dup.h"
#include "../command/len.h"
#include "../command/slice.h"
#include "../command/find.h"


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
    s_commands.insert(std::pair<std::string, ICommand*>("load", new Load));
    s_commands.insert(std::pair<std::string, ICommand*>("save", new Save));
    s_commands.insert(std::pair<std::string, ICommand*>("dup", new Dup));
    s_commands.insert(std::pair<std::string, ICommand*>("len", new Len));
    s_commands.insert(std::pair<std::string, ICommand*>("slice", new Slice));
    s_commands.insert(std::pair<std::string, ICommand*>("find", new Find));
}

void Factory::release()
{
    delete s_commands.at("new");
    delete s_commands.at("load");
    delete s_commands.at("save");
    delete s_commands.at("dup");
    delete s_commands.at("len");
    delete s_commands.at("slice");
    delete s_commands.at("find");
}
