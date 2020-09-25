#include "concat.h"
#include "../AuxiliaryFunc.h"


size_t findId(const Params& params, DnaHash& dnaHash, IWriter& writer, size_t i)
{
    size_t id = 0;

    if (params.getParams()[i][0] == '@')
    {
        if (!dnaHash.isExistName(params.getParams()[i].substr(1)))
        {
            writer.write("name of DNA not found\n");
            return 0;
        }

        id = dnaHash.findIdByName(params.getParams()[i].substr(1));
    }

    else
    {
        id = castToSize(params.getParams()[i].substr(1));

        if (!dnaHash.isExistId(id))
        {
            writer.write("id of DNA not found\n");
            return 0;
        }
    }

    return id;
}

std::string nameId(const Params& params, DnaHash& dnaHash, IWriter& writer, size_t i)
{
    size_t id = findId(params, dnaHash, writer, i);
    std::string name = dnaHash.getIDMap()[id]->getName();
    return name;
}

std::string concat(const Params& params, DnaHash& dnaHash, IWriter& writer, size_t i)
{
    size_t id = findId(params, dnaHash, writer, i);
    std::string seq = dnaHash.getIDMap()[id]->getDnaSequence().castChar();
    return seq;
}

void Concat::createCommand(const Params& params)
{
    isValid(params);
}

void Concat::isValid(const Params& params)
{
    size_t len = params.getParams().size();

    if (params.getParams().size() < 2)
    {
        throw std::invalid_argument("INVALID NUM OF ARGUMENTS\n");
    }

    if (params.getParams()[len - 2][0] == ':')
    {
        len -= 2;
    }

    for(size_t i = 0; i < len ; ++i)
    {
        if (!(params.getParams()[i][0] == '@' || params.getParams()[i][0] == '#'))
        {
            throw std::invalid_argument("THE COMMAND DOESN'T KNOW WHICH DNA TO REFER\n");
        }
    }
}

std::string Concat::run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader)
{
    static size_t count1 = 0, count2 = 0;
    size_t len = params.getParams().size();

    size_t id = findId(params, dnaHash, writer, 0);
    std::string str = dnaHash.getIDMap()[id]->getDnaSequence().castChar();
    std::string name = dnaHash.getIDMap()[id]->getName();

    for(size_t i = 1; i < len; ++i)
    {
        if (params.getParams()[i][0] == ':')
        {
            break;
        }

        str += concat(params, dnaHash, writer, i);
        name += '_' + nameId(params, dnaHash, writer, i);
    }

    DnaSequence concatDna(str);

    if (params.getParams()[len - 2][0] != ':')
    {
        dnaHash.getIDMap()[id]->setSeq(concatDna);
        dnaHash.getIDMap()[id]->getStatus().setStatus("modified");

        return castStr(dnaHash, id);
    }

    else
    {
        std::string newName;

        if (params.getParams()[len-1][1] == '@')
        {
            std::stringstream nameTemp;

            if (len == 4)
            {
                nameTemp << name << '_' << 'c' << ++count1;
            }

            else
            {
                nameTemp << "conseq_" << ++count2;
            }

            newName = nameTemp.str();
        }

        else
        {
            newName = params.getParams()[len - 1].substr(1);
        }

        DnaMetaData* newDna = new DnaMetaData(concatDna, newName, (std::string)"new");
        dnaHash.add(newDna);

        return castStr(dnaHash, dnaHash.getIDMap()[DnaMetaData::getId()]->getId());
    }
}

std::string Concat::castStr(DnaHash &dnaHash, size_t id)
{
    std::stringstream stringstream;
    stringstream << id;

    return ("[" + stringstream.str() + "] " + dnaHash.getIDMap()[id]->getName() + ": " + dnaHash.getIDMap()[id]->getDnaSequence().castChar() + '\n' + '\n');
}
