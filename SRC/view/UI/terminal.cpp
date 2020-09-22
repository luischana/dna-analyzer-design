#include <iostream>
#include "terminal.h"
#include "../write/IWriter.h"
#include "controler/factory/factory.h"
#include "../read/ConsoleRead.h"


void Terminal::doAction(IReader& reader, IWriter& writer, DnaHash& dnaHash)
{
    Factory::init();

    while(1)
    {
        Params p;
        reader.read();
        p.params(reader.getStr());

        try
        {
            ICommand *command = Factory::create(p);
            command->run(p, dnaHash, writer);
        }

        catch (std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        };
    }

    Factory::release();
}
