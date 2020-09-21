#include "AuxiliaryFunc.h"


size_t castToSize(std::string string)
{
    std::stringstream temp(string);
    size_t idDna;
    temp >> idDna;
    return idDna;
}
