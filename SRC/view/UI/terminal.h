#ifndef SRC_TERMINAL_H
#define SRC_TERMINAL_H


#include "UserInterface.h"

class Terminal: public UserInterface {
public:
    /*virtual*/ void doAction(IReader& reader, IWriter& writer, DnaHash& dnaHash);
};



#endif //SRC_TERMINAL_H
