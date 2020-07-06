#include "Params.h"

void Params::paramCmd(std::string cmd)
{
    size_t pos = 0;

    if((pos = cmd.find(' ')) == std::string::npos)
    {
        m_commandName = cmd;
        return;
    }

    m_commandName = cmd.substr(0, pos);
    cmd.erase(0, pos+1);

    while((pos = cmd.find(' ')) == std::string::npos)
    {
        m_vectorParams.push_back(cmd.substr(0, pos));
        cmd.erase(0, pos+1);
    }

    m_vectorParams.push_back(cmd);
}