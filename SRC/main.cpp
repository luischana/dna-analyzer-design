#include "controler/system.h"
#include "view/UI/terminal.h"
#include "view/read/ConsoleRead.h"
#include "view/write/ConsoleWriter.h"

int main() {
    System program;

    ConsoleRead reader;
    ConsoleWriter writer;
    Terminal terminal;

    writer.write("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n          Welcome to Dnalanyzer System            \n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    program.start(reader, writer, &terminal);

    return 0;
}