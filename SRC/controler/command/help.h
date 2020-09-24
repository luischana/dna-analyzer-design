#ifndef SRC_HELP_H
#define SRC_HELP_H


#include "ControlCommand.h"

class Help: public ControlCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ void run(const Params& params, DnaHash& dnaHash, IWriter& writer);
    static void initializeMapAbout();

private:
    static std::map<std::string, std::string> m_mapAbout;
};


#endif //SRC_HELP_H
