#include "System.h"


void System::start(IReader& reader, IWriter& writer, UserInterface* UI)
{
    DnaHash dnaHash;
    UI->doAction(reader, writer, dnaHash);
}