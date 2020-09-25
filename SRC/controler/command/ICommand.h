#ifndef SRC_ICOMMAND_H
#define SRC_ICOMMAND_H


#include "../params/Params.h"
#include "../../model/DnaHash.h"
#include "../../view/write/IWriter.h"
#include "../../view/read/IReader.h"

class ICommand {
public:
    virtual ~ICommand() {}
    virtual void createCommand(const Params& params) = 0;
    virtual std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader) = 0;
};


#endif //SRC_ICOMMAND_H
