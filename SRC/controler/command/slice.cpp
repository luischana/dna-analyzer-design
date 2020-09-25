#include "slice.h"
#include "../AuxiliaryFunc.h"


void Slice::createCommand(const Params& params)
{
    isValid(params);
}

void Slice::isValid(const Params& params)
{
    if (!(params.getParams().size() == 3 || params.getParams().size() == 5))
    {
        throw std::invalid_argument("INVALID NUM OF ARGUMENTS\n");
    }

    if (!(params.getParams()[0][0] == '@' || params.getParams()[0][0] == '#'))
    {
        throw std::invalid_argument("THE COMMAND DOESN'T KNOW WHICH DNA TO REFER\n");
    }

    if (params.getParams().size() == 5 && (params.getParams()[3] != ":" || params.getParams()[4][0] != '@'))
    {
        throw std::invalid_argument("INVALID ARGUMENTS\n");
    }
}

std::string Slice::run(const Params& params, DnaHash& dnaHash, IWriter& writer, IReader& reader)
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

    size_t fromInd = castToSize(params.getParams()[1].c_str());
    size_t toInd = castToSize(params.getParams()[2].c_str());

    DnaSequence seq = dnaHash.getIDMap()[id]->getDnaSequence();
    DnaSequence sliceDna(seq.slice(fromInd, toInd));

    if (params.getParams().size() == 3)
    {
        dnaHash.getIDMap()[id]->setSeq(sliceDna);
        dnaHash.getIDMap()[id]->getStatus().setStatus("modified");

        return castStr(dnaHash, id);
    }

    else
    {
        std::string newName;

        if (params.getParams()[4][1] == '@')
        {
            std::string oldName = dnaHash.getIDMap()[id]->getName();

            std::stringstream name;
            name << oldName << '_' << 's' << dnaHash.getIDMap()[dnaHash.getNameMap()[oldName]]->getCount();
            newName = name.str();
        }

        else
        {
            newName = params.getParams()[4].substr(1);
        }

        DnaMetaData* newDna = new DnaMetaData(sliceDna, newName, (std::string)"new");
        dnaHash.add(newDna);

        return castStr(dnaHash, dnaHash.getIDMap()[DnaMetaData::getId()]->getId());
    }
}

std::string Slice::castStr(DnaHash& dnaHash, size_t id)
{
    std::stringstream string;
    string << id;

    return ("[" + string.str() + "] " + dnaHash.getIDMap()[id]->getName() + ": " + dnaHash.getIDMap()[id]->getDnaSequence().castChar() + '\n');
}
