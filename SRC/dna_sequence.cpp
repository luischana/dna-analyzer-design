#include <string>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include "dna_sequence.h"

DnaSequence::Nucleotide::Nucleotide():m_char('\0') {}

DnaSequence::Nucleotide::Nucleotide(char c):m_char(c) {}

DnaSequence::Nucleotide& DnaSequence::Nucleotide::operator=(char c)
{
    if(isValid(c))
    {
        m_char = c;
    }

    return *this;
}

char DnaSequence::Nucleotide::getChar()const
{
    return m_char;
}

DnaSequence::Nucleotide DnaSequence::Nucleotide::changeChar()
{
    if(m_char == 'A')
        return 'T';

    else if(m_char == 'C')
        return 'G';

    else if(m_char == 'T')
        return 'A';

    else
        return 'C';
}

bool DnaSequence::Nucleotide::isValid(const char c)
{
    if(c != 'A' and c != 'C' and c != 'G' and c != 'T')
    {
        throw std::invalid_argument("invalid argument");
    }

    return true;
}

DnaSequence::DnaSequence(const char* dnaSequence)
{
    if(isValidDnaSequence(dnaSequence))
    {
        m_lenDnaSequence = strlen(dnaSequence);
        initDnaSequence(dnaSequence);
    }
}

DnaSequence::DnaSequence(const std::string& dnaSequence)
{
    if(isValidDnaSequence(dnaSequence.c_str()))
    {
        m_lenDnaSequence = dnaSequence.length();
        initDnaSequence(dnaSequence.c_str());
    }
}

DnaSequence::DnaSequence(size_t lenDnaSequence)
{
    m_lenDnaSequence = lenDnaSequence;
    m_dnaSequence = new Nucleotide[lenDnaSequence + 1];
}

DnaSequence::DnaSequence(const IReader& dnaSequence)
{
    if(isValidDnaSequence(dnaSequence.read().c_str()))
    {
        m_lenDnaSequence = strlen(dnaSequence.read().c_str());
        initDnaSequence(dnaSequence.read().c_str());
    }
}

DnaSequence::~DnaSequence()
{
    delete[] m_dnaSequence;
    m_dnaSequence = NULL;
}

DnaSequence::DnaSequence(const DnaSequence& dnaSequence)
{
    m_lenDnaSequence = dnaSequence.m_lenDnaSequence;
    initDnaSequence(dnaSequence.castChar());
}

const DnaSequence& DnaSequence::operator=(const DnaSequence &dnaSequence)
{
    if(this == &dnaSequence)
        return *this;

    delete[] m_dnaSequence;
    initDnaSequence(dnaSequence.castChar());

    return *this;
}

DnaSequence::Nucleotide& DnaSequence::operator[](size_t index) const
{
    if(index < m_lenDnaSequence)
    {
        return m_dnaSequence[index];
    }

    throw std::invalid_argument("index isn't valid!!!");
}

size_t DnaSequence::lenght() const
{
    return m_lenDnaSequence;
}

const char* DnaSequence::castChar() const
{
    return (char*)m_dnaSequence;
}

bool DnaSequence::isValidDnaSequence(const char *dnaSequence)
{
    if(!dnaSequence)
    {
        throw std::invalid_argument("DNA isn't valid!!!");
    }

    if(strlen(dnaSequence) != strspn(dnaSequence, "ACGT"))
    {
        throw std::invalid_argument("DNA isn't valid!");
    }

    return true;
}

void DnaSequence::initDnaSequence(const char *dnaSequence)
{
    m_dnaSequence = new Nucleotide[m_lenDnaSequence + 1];

    for(size_t i = 0; i < m_lenDnaSequence; i++)
    {
        m_dnaSequence[i] = dnaSequence[i];
    }
}

std::ostream& operator<<(std::ostream &out, const DnaSequence &dnaSequence)
{
    out << "DnaSequence: " << dnaSequence.castChar() << std::endl;
    return out;
}

DnaSequence DnaSequence::slice(size_t startIdx, size_t endIdx)
{
    if(startIdx > endIdx)
    {
        throw std::invalid_argument("startIdx bigger than endIdx");
    }

    DnaSequence dnaSequence(endIdx - startIdx);

    for(size_t i = startIdx; i < endIdx; i++)
    {
        dnaSequence.m_dnaSequence[i-startIdx] = m_dnaSequence[i];
    }

    return dnaSequence;
}

DnaSequence DnaSequence::pairing()
{
    DnaSequence dnaSequence(m_lenDnaSequence);

    for(size_t i = 0; i < m_lenDnaSequence ;i++)
    {
        dnaSequence.m_dnaSequence[i] = m_dnaSequence[m_lenDnaSequence-i-1].changeChar();
    }

    return dnaSequence;
}

size_t DnaSequence::find(const DnaSequence& dnaSequence)
{
    std::string strM_DnaSequence = castChar();
    std::string strDnaSequence = dnaSequence.castChar();

    if(strM_DnaSequence.find(strDnaSequence) == std::string::npos)
    {
        return dnaSequence.m_lenDnaSequence;
    }

    return strM_DnaSequence.find(strDnaSequence);
}

size_t DnaSequence::count(const DnaSequence& dnaSequence)
{
    size_t count = 0;

    for(size_t i = 0; i <= m_lenDnaSequence - dnaSequence.m_lenDnaSequence; i++)
    {
        if(m_dnaSequence[i] == dnaSequence[0] && slice(i, i + dnaSequence.m_lenDnaSequence).find(dnaSequence) == 0)
        {
            count++;
        }
    }

    return count;
}

std::list<size_t>DnaSequence::findAll(const DnaSequence &dnaSequence)
{
    std::list<size_t> AllDna;

    for(size_t i = 0; i <= m_lenDnaSequence - dnaSequence.m_lenDnaSequence; i++)
    {
        if(m_dnaSequence[i] == dnaSequence[0] && slice(i, i + dnaSequence.m_lenDnaSequence).find(dnaSequence) == 0)
        {
            AllDna.push_back(i);
        }
    }

    return AllDna;
}

void DnaSequence::createConsensusSequences(std::list<DnaSequence>& consensusSequencesList, std::list<size_t>& startCodonList, std::list<size_t>& endCodonList)
{
    std::list<size_t>::iterator iterStartCodon;
    std::list<size_t>::iterator iterEndCodon;

    for (iterStartCodon = startCodonList.begin(); iterStartCodon != startCodonList.end(); iterStartCodon++)
    {
        for (iterEndCodon = endCodonList.begin(); iterEndCodon != endCodonList.end(); iterEndCodon++)
        {
            if (*iterStartCodon < *iterEndCodon && (*iterEndCodon - *iterStartCodon) % 3 == 0)
            {
                consensusSequencesList.push_back(slice(*iterStartCodon, *iterEndCodon + 3));
            }
        }
    }
}

std::list<DnaSequence> DnaSequence::findConsensusSequences()
{
    std::list<DnaSequence> consensusSequencesList;
    std::list<size_t> startCodonIndexesATG = findAll("ATG");
    std::list<size_t> endCodonIndexesTAG = findAll("TAG");
    std::list<size_t> endCodonIndexesTAA = findAll("TAA");
    std::list<size_t> endCodonIndexesTGA = findAll("TGA");

    createConsensusSequences(consensusSequencesList, startCodonIndexesATG, endCodonIndexesTAG);
    createConsensusSequences(consensusSequencesList, startCodonIndexesATG, endCodonIndexesTAA);
    createConsensusSequences(consensusSequencesList, startCodonIndexesATG, endCodonIndexesTGA);

    return consensusSequencesList;
}

bool operator==(const DnaSequence &dnaSequence1, const DnaSequence &dnaSequence2)
{
    return strcmp(dnaSequence1.castChar(), dnaSequence2.castChar()) == 0;
}

bool operator!=(const DnaSequence &dnaSequence1, const DnaSequence &dnaSequence2)
{
    return strcmp(dnaSequence1.castChar(), dnaSequence2.castChar()) != 0;
}
