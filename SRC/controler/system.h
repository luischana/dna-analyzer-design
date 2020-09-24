#ifndef SRC_SYSTEM_H
#define SRC_SYSTEM_H


#include "../view/UI/UserInterface.h"
#include "../view/read/IReader.h"
#include "../view/write/IWriter.h"

class System {
public:
    void start(IReader& reader, IWriter& writer, UserInterface* UI);
};


#endif //SRC_SYSTEM_H
