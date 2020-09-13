#ifndef SRC_MANAGER_H
#define SRC_MANAGER_H


#include "../read/IReader.h"
#include "../write/IWriter.h"
#include "../DNA/DnaHash.h"

class Manager {
public:
    void doAction(IReader& reader, IWriter& writer, DnaHash& dnaHash);
};



#endif //SRC_MANAGER_H
