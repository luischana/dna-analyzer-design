#include "help.h"


std::map<std::string, std::string> Help::m_mapAbout;

void Help::initializeMapAbout()
{
    m_mapAbout.insert(std::pair<std::string, std::string >("new","Creates a new sequence"));
    m_mapAbout.insert(std::pair<std::string, std::string >("load","Loads the sequence from the file"));
    m_mapAbout.insert(std::pair<std::string, std::string >("dup","Duplicates the sequence"));
    m_mapAbout.insert(std::pair<std::string, std::string >("slice","Slices the sequence"));
    m_mapAbout.insert(std::pair<std::string, std::string >("replace","Replaces the letter in the index of seq by new_letter"));
    m_mapAbout.insert(std::pair<std::string, std::string >("concat","Concatenates seq_2 at the end of seq_1"));
    m_mapAbout.insert(std::pair<std::string, std::string >("rename","Renames the name of the sequence to the new name"));
    m_mapAbout.insert(std::pair<std::string, std::string >("save","Saves seq to a file"));
    m_mapAbout.insert(std::pair<std::string, std::string >("len","Prints the length of the sequence"));
    m_mapAbout.insert(std::pair<std::string, std::string >("find","Finds a sub-sequence within a sequence"));
    m_mapAbout.insert(std::pair<std::string, std::string >("count","Returns the number of instances of the sub-sequence within the larger sequence"));
    m_mapAbout.insert(std::pair<std::string, std::string >("findall","Return all the indices where the sub-sequence appears"));
    m_mapAbout.insert(std::pair<std::string, std::string >("help","Shows a short explanation of command"));
    m_mapAbout.insert(std::pair<std::string, std::string >("quit","Prints a goodbye message and the application exists"));
}

void Help::createCommand(const Params& params)
{
    isValid(params);
}

void Help::isValid(const Params& params)
{
    if (params.getParams().size() > 1)
    {
        throw std::invalid_argument("INVALID NUM OF ARGUMENTS\n");
    }
}

std::string Help::run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader)
{
    std::string commands;

    if (params.getParams().empty())
    {
        std::map<std::string, std::string>::iterator iter;

        for(iter = m_mapAbout.begin(); iter != m_mapAbout.end(); ++iter)
        {
            commands += iter->first + '\n';
        }

        return commands;
    }

    else
    {
        if (m_mapAbout.find(params.getParams()[0]) != m_mapAbout.end())
        {
            return (m_mapAbout[params.getParams()[0]] + '\n');
        }

        else
        {
            return "This comand not exist\n";
        }
    }
}
