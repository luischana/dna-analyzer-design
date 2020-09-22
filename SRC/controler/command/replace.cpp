#include <sstream>
#include "replace.h"
#include "../AuxiliaryFunc.h"


void Replace::createCommand(const Params& params)
{
    isValid(params);
}

void Replace::isValid(const Params& params)
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

void Replace::run(const Params &params, DnaHash& dnaHash, IWriter& writer)
{
    size_t id = 0;

    if (params.getParams()[0][0] == '@')
    {
        if (!dnaHash.isExistName(params.getParams()[0].substr(1)))
        {
            writer.write("name of DNA not found\n");
            return;
        }

        id = dnaHash.findIdByName(params.getParams()[0].substr(1));
    }

    else
    {
        id = castToSize(params.getParams()[0].substr(1));

        if (!dnaHash.isExistId(id))
        {
            writer.write("id of DNA not found\n");
            return;
        }
    }

    std::string seq = dnaHash.getIDMap()[id]->getDnaSequence().castChar();
    size_t index = castToSize(params.getParams()[1]);
    std::string newSeq = params.getParams()[2];

    DnaSequence replaceDna(seq.replace(index, newSeq.length(), newSeq));

    if (params.getParams().size() == 3)
    {
        dnaHash.getIDMap()[id]->setSeq(replaceDna);
        print(dnaHash, writer, id);
    }

    else /*param.getParam().size() == 5*/
    {
        std::string newName;

        if (params.getParams()[4][1] == '@')
        {
            std::string oldName;
            oldName = dnaHash.getIDMap()[id]->getName();

            std::stringstream name;
            name << oldName << '_' << 'r' << dnaHash.getIDMap()[dnaHash.getNameMap()[oldName]]->getCount();
            newName = name.str();
        }

        else
        {
            newName = params.getParams()[4].substr(1);
        }

        DnaMetaData* newDnaSequence = new DnaMetaData(replaceDna, newName, (std::string)"replace");
        dnaHash.add(newDnaSequence);
        print(dnaHash, writer, dnaHash.getIDMap()[DnaMetaData::getId()]->getId());
    }

}

void Replace::print(DnaHash &dnaHash, IWriter &writer, size_t id)
{
    std::stringstream stringstream;

    stringstream << id;

    writer.write("[" + stringstream.str() + "] " + dnaHash.getIDMap()[id]->getName() + ": " + dnaHash.getIDMap()[id]->getDnaSequence().castChar() + '\n');
}