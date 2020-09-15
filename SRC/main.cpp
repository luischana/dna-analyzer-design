#include "controler/System.h"
#include "view/UI/Terminal.h"
#include "view/read/ConsoleRead.h"
#include "view/write/ConsoleWriter.h"

int main() {
    System program;

    ConsoleRead reader;
    ConsoleWriter writer;
    Terminal terminal;

    program.start(reader, writer, &terminal);

    return 0;
}