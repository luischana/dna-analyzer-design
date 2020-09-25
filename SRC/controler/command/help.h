#ifndef SRC_HELP_H
#define SRC_HELP_H


#include "ControlCommand.h"

class Help: public ControlCommand {
public:
    /*virtual*/ void createCommand(const Params& params);
    void isValid(const Params& params);
    /*virtual*/ std::string run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader);
    static void initializeMapAbout();

private:
    static std::map<std::string, std::string> m_mapAbout;
};


#endif //SRC_HELP_H
