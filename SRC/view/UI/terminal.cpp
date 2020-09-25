#include <iostream>
#include "terminal.h"
#include "../write/IWriter.h"
#include "../../controler/factory/factory.h"


void Terminal::doAction(IReader& reader, IWriter& writer, DnaHash& dnaHash)
{
    Factory::init();

    while(true)
    {
        Params p;
        writer.write("> cmd >>>");
        reader.read();
        p.params(reader.getStr());

        try
        {
            ICommand *command = Factory::create(p);
            std::string str = command->run(p, dnaHash, writer, reader);

            if (str == "quit")
            {
                break;
            }

            writer.write(str);
        }

        catch (std::exception& ex)
        {
            std::cout << ex.what() << std::endl;
        };
    }

    Factory::release();
}
