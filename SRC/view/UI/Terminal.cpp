#include <iostream>
#include "Terminal.h"
#include "../write/IWriter.h"
#include "../../controler/factory/Factory.h"
#include "../read/ConsoleRead.h"


void Terminal::doAction(IReader& reader, IWriter& writer, DnaHash& dnaHash)
{
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
}
