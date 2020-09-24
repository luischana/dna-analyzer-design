#include <iostream>
#include "factory.h"
#include "../command/new.h"
#include "../command/load.h"
#include "../command/save.h"
#include "../command/dup.h"
#include "../command/len.h"
#include "../command/slice.h"
#include "../command/find.h"
#include "../command/count.h"
#include "../command/findAll.h"
#include "../command/rename.h"
#include "../command/replace.h"
#include "../command/concat.h"
#include "../command/help.h"


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
        return s_commands.at("new");
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
    s_commands.insert(std::pair<std::string, ICommand*>("count", new Count));
    s_commands.insert(std::pair<std::string, ICommand*>("findAll", new FindAll));
    s_commands.insert(std::pair<std::string, ICommand*>("rename", new Rename));
    s_commands.insert(std::pair<std::string, ICommand*>("replace", new Replace));
    s_commands.insert(std::pair<std::string, ICommand*>("concat", new Concat));
    s_commands.insert(std::pair<std::string, ICommand*>("help", new Help));
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
    delete s_commands.at("count");
    delete s_commands.at("findAll");
    delete s_commands.at("rename");
    delete s_commands.at("replace");
    delete s_commands.at("concat");
    delete s_commands.at("help");
}
