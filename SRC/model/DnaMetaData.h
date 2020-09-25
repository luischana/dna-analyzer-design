#ifndef SRC_DNAMETADATA_H
#define SRC_DNAMETADATA_H

#include <string>
#include "DnaSequence.h"
#include "Status.h"

class DnaMetaData {
public:
    DnaMetaData(const DnaSequence& dnaSequence, std::string name, const Status& status);
    const DnaSequence& getDnaSequence() const { return m_dnaSequence; }
    const std::string& getName() const        { return m_name; }
    static size_t getId()                     { return m_id; }
    Status& getStatus()                       { return m_status; }
    size_t getCount()                         { return ++m_count; }
    void setSeq(const DnaSequence& seq);
    void setName(std::string name);

private:
    DnaSequence   m_dnaSequence;
    std::string   m_name;
    static size_t m_id;
    Status        m_status;
    size_t        m_count;
};


inline DnaMetaData::DnaMetaData(const DnaSequence& dnaSequence, std::string name, const Status& status): m_dnaSequence(dnaSequence), m_name(name), m_status(status), m_count(0)
{
    ++m_id;
}

inline void DnaMetaData::setSeq(const DnaSequence &seq)
{
    m_dnaSequence = seq;
}

inline void DnaMetaData::setName(std::string name)
{
    m_name = name;
}


#endif //SRC_DNAMETADATA_H
