#ifndef SRC_TXTFILEWRITER_H
#define SRC_TXTFILEWRITER_H


class TxtFileWriter: public FileWriter {
public:
    TxtFileWriter(std::string fileName);
    /*virtual*/ void write(std::string str) const;

private:
    std::string m_fileName;
};


#endif //SRC_TXTFILEWRITER_H
