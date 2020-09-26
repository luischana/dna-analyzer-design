#ifndef SRC_STATUS_H
#define SRC_STATUS_H


#include <string>
#include <vector>

class Status {
public:
    Status(const std::string& status):m_status(status){}
    std::string getStatus()                   { return m_status; }
    void setStatus(const std::string& status) { m_status = status; }
    static std::vector<int> s_vecStatus;

private:
    std::string m_status;
};


#endif //SRC_STATUS_H
