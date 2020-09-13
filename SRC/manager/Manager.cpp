#include "Manager.h"
#include "../write/IWriter.h"
#include "../factory/Factory.h"
#include "../read/ConsoleRead.h"


void Manager::doAction(IReader& reader, IWriter& writer, DnaHash& dnaHash)
{
    while(1)
    {
        Params p;
        reader.read();
        p.params(reader.getStr());
        ICommand* command = Factory::create(p);
        command->run(p, dnaHash, writer);
    }
}