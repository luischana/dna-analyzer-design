#ifndef SRC_DNAMETADATA_H
#define SRC_DNAMETADATA_H

#include <string>
#include "DnaSequence.h"
#include "Status.h"

class DnaMetaData {
public:
    DnaMetaData(const DnaSequence& dnaSequence, std::string name, const Status& status);
    DnaSequence getDnaSequence() const { return m_dnaSequence; }
    std::string getName() const { return m_name; }
    static size_t getId() { return m_id; }
    const Status getStatus() const { return m_status; }

private:
    DnaSequence m_dnaSequence;
    std::string m_name;
    static size_t m_id;
    Status m_status;
};


inline DnaMetaData::DnaMetaData(const DnaSequence& dnaSequence, std::string name, const Status& status): m_dnaSequence(dnaSequence), m_name(name), m_status(status)
{
    ++m_id;
}


#endif //SRC_DNAMETADATA_H
