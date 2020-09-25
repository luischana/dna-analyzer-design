#include <iostream>
#include "replace.h"
#include "../AuxiliaryFunc.h"


void Replace::createCommand(const Params& params)
{
    isValid(params);
}

void Replace::isValid(const Params& params)
{
    if (params.getParams().size() < 3 && params.getParams().size() % 2 != 1)
    {
        throw std::invalid_argument("INVALID NUM OF ARGUMENTS\n");
    }

    if (!(params.getParams()[0][0] == '@' || params.getParams()[0][0] == '#'))
    {
        throw std::invalid_argument("THE COMMAND DOESN'T KNOW WHICH DNA TO REFER\n");
    }
}

std::string replaceDna(const Params& params, std::string seq)
{
    size_t len = params.getParams().size() - 1;

    if (params.getParams()[len-1][0] == ':')
    {
        len -= 2;
    }

    size_t i = 1;
    size_t index;
    std::string newLetter;

    while(i < len)
    {
        index = castToSize(params.getParams()[i]);
        newLetter = params.getParams()[i+1];

        if (index >= seq.length())
        {
            std::cout << "index not found\n"<< std::endl;
            break;
        }

        seq.replace(index, newLetter.length(), newLetter);

        i += 2;
    }

    return seq;
}

std::string Replace::run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader)
{
    size_t id = 0;

    if (params.getParams()[0][0] == '@')
    {
        if (!dnaHash.isExistName(params.getParams()[0].substr(1)))
        {
            return "name of DNA not found\n";
        }

        id = dnaHash.findIdByName(params.getParams()[0].substr(1));
    }

    else
    {
        id = castToSize(params.getParams()[0].substr(1));

        if (!dnaHash.isExistId(id))
        {
            return "id of DNA not found\n";
        }
    }

    std::string seq = dnaHash.getIDMap()[id]->getDnaSequence().castChar();
    size_t len = params.getParams().size() - 1;

    DnaSequence replaceDnaSeq(replaceDna(params, seq));

    if (params.getParams()[len-1][0] != ':')
    {
        dnaHash.getIDMap()[id]->setSeq(replaceDnaSeq);
        dnaHash.getIDMap()[id]->getStatus().setStatus("modified");

        return castStr(dnaHash, id);
    }

    else
    {
        std::string newName;

        if (params.getParams()[len][1] == '@')
        {
            std::string oldName;
            oldName = dnaHash.getIDMap()[id]->getName();

            std::stringstream name;
            name << oldName << '_' << 'r' << dnaHash.getIDMap()[dnaHash.getNameMap()[oldName]]->getCount();
            newName = name.str();
        }

        else
        {
            newName = params.getParams()[len].substr(1);
        }

        DnaMetaData* newDna = new DnaMetaData(replaceDnaSeq, newName, (std::string)"new");
        dnaHash.add(newDna);

        return castStr(dnaHash, dnaHash.getIDMap()[DnaMetaData::getId()]->getId());
    }
}

std::string Replace::castStr(DnaHash& dnaHash, size_t id)
{
    std::stringstream stringstream;
    stringstream << id;

    return ("[" + stringstream.str() + "] " + dnaHash.getIDMap()[id]->getName() + ": " + dnaHash.getIDMap()[id]->getDnaSequence().castChar() + '\n');
}
