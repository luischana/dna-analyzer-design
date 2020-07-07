#ifndef SRC_PARAMS_H
#define SRC_PARAMS_H


#include <string>
#include <vector>

class Params {
public:
    void params(std::string cmd);
    const std::string& getCmdName() const { return m_commandName; }
    const std::vector<std::string>& getParams() const { return m_vectorParams; }

private:
    std::string m_commandName;
    std::vector<std::string> m_vectorParams;
};


#endif //SRC_PARAMS_H
