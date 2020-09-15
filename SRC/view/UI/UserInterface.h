#ifndef SRC_USERINTERFACE_H
#define SRC_USERINTERFACE_H


#include "../../model/DnaHash.h"
#include "../read/ConsoleRead.h"
#include "../write/ConsoleWriter.h"

class UserInterface {
public:
    virtual void doAction(IReader& reader, IWriter& writer, DnaHash& dnaHash) = 0;
};


#endif //SRC_USERINTERFACE_H
