#ifndef DNA_DNA_SEQUENCE_H
#define DNA_DNA_SEQUENCE_H

#include <list>
#include <string>
#include <fstream>

class DnaSequence {
private:
    class Nucleotide {
    public:
        Nucleotide();
        Nucleotide(char c);
        Nucleotide& operator=(char c);
        char getChar()const;
        operator char(){
            return m_char;
        };
        Nucleotide changeChar();

    private:
        char m_char;
        bool isValid(const char c);
    };

public:
    DnaSequence(const char* dnaSequence);
    DnaSequence(const std::string& dnaSequence);
    DnaSequence(size_t lenDnaSequence);
    ~DnaSequence();
    DnaSequence(const DnaSequence& dnaSequence);
    const DnaSequence& operator=(const DnaSequence& dnaSequence);

    Nucleotide& operator[](size_t index)const;
    size_t lenght()const;
    const char* castChar()const;
    friend std::ostream& operator<<(std::ostream& out, const DnaSequence& dnaSequence);
    DnaSequence slice(size_t startIdx, size_t endIdx)const;
    DnaSequence pairing();
    size_t find(const DnaSequence& dnaSequence)const;
    size_t count(const DnaSequence& dnaSequence)const;
    std::list<size_t> findAll(const DnaSequence& dnaSequence)const;
    void createConsensusSequences(std::list<DnaSequence>& consensusSequencesList, std::list<size_t>& startCodonList, std::list<size_t>& endCodonList);
    std::list<DnaSequence> findConsensusSequences();

private:
    bool isValidDnaSequence(const char* dnaSequence);
    void initDnaSequence(const char* dnaSequence);

    Nucleotide* m_dnaSequence;
    size_t m_lenDnaSequence;
};

bool operator==(const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2);
bool operator!=(const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2);


#endif //DNA_DNA_SEQUENCE_H
