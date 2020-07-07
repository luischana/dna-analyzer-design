#include "Manager.h"
#include "IWriter.h"
#include "Factory.h"
#include "ConsoleRead.h"


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