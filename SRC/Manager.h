#ifndef SRC_MANAGER_H
#define SRC_MANAGER_H


#include "IReader.h"
#include "IWriter.h"
#include "DnaHash.h"

class Manager {
public:
    void doAction(IReader& reader, IWriter& writer, DnaHash& dnaHash);
};



#endif //SRC_MANAGER_H
