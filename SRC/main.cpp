#include "Manager.h"
#include "ConsoleRead.h"
#include "IWriter.h"

int main() {
    Manager manager;
    ConsoleRead reader;
    ConsoleWriter writer;
    DnaHash dnaHash;
    manager.doAction(reader, writer, dnaHash);

    return 0;
}