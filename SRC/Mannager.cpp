#include "Mannager.h"
#include "IReader.h"
#include "IWriter.h"
#include "Factory.h"


void Mannager::doAction()
{
    ConsoleRead reader;
    ConsoleWriter writer;

    Params params(reader.read());
    Factory::create(params)->run(params);

    writer.write(params.getParams()[0].c_str());
    writer.write(params.getParams()[1].c_str());
    writer.write(params.getParams()[2].c_str());
}