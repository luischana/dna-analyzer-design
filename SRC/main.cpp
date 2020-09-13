#include "manager/Manager.h"
#include "read/ConsoleRead.h"
#include "write/ConsoleWriter.h"

int main() {
    Manager manager;
    ConsoleRead reader;
    ConsoleWriter writer;
    DnaHash dnaHash;
    manager.doAction(reader, writer, dnaHash);

    return 0;
}