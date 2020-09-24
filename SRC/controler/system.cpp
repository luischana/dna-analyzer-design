#include "System.h"
#include "command/help.h"


void System::start(IReader& reader, IWriter& writer, UserInterface* UI)
{
    DnaHash dnaHash;
    Help::initializeMapAbout();
    UI->doAction(reader, writer, dnaHash);
}