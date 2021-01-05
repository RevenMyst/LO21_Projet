#include "OpeFactory.h"

std::map<std::string, Operator*> OpeFactory::getOpeFactories()
{
    std::map<std::string, Operator*>factories;
    std::pair<std::string, Operator*> entry;

	entry.first = "DUP";
    entry.second = new OpeDUP();
	factories.insert(entry);

	entry.first = "DROP";
    entry.second = new OpeDROP();
	factories.insert(entry);

	entry.first = "SWAP";
    entry.second = new OpeSWAP();
	factories.insert(entry);

	entry.first = "CLEAR";
    entry.second = new OpeCLEAR();
	factories.insert(entry);

	entry.first = "STO";
    entry.second = new OpeSTO();
	factories.insert(entry);

	entry.first = "FORGET";
    entry.second = new OpeFORGET();
	factories.insert(entry);

	entry.first = "EVAL";
    entry.second = new OpeEVAL();
	factories.insert(entry);

	entry.first = "AND";
    entry.second = new OpeAND();
	factories.insert(entry);

	entry.first = "OR";
    entry.second = new OpeOR();
	factories.insert(entry);

	entry.first = "+";
    entry.second = new OpePlus();
	factories.insert(entry);

	entry.first = "-";
    entry.second = new OpeMoins();
	factories.insert(entry);

	entry.first = "*";
    entry.second = new OpeMul();
	factories.insert(entry);

	entry.first = "/";
    entry.second = new OpeDivision();
	factories.insert(entry);

	entry.first = "=";
    entry.second = new OpeEQUAL();
	factories.insert(entry);

	entry.first = "!=";
    entry.second = new OpeDIF();
	factories.insert(entry);

	entry.first = ">";
    entry.second = new OpeGT();
	factories.insert(entry);

	entry.first = "<";
    entry.second = new OpeLT();
	factories.insert(entry);

	entry.first = ">=";
    entry.second = new OpeGTE();
	factories.insert(entry);

	entry.first = "<=";
    entry.second = new OpeLTE();
	factories.insert(entry);

	entry.first = "DIV";
    entry.second = new OpeDIV();
	factories.insert(entry);

	entry.first = "MOD";
    entry.second = new OpeMOD();
	factories.insert(entry);

	entry.first = "IFT";
    entry.second = new OpeIFT();
	factories.insert(entry);

	entry.first = "IFTE";
    entry.second = new OpeIFTE();
	factories.insert(entry);

    entry.first = "WHILE";
    entry.second = new OpeWHILE();
    factories.insert(entry);

	entry.first = "NOT";
    entry.second = new OpeNOT();
	factories.insert(entry);

	entry.first = "NEG";
    entry.second = new OpeNEG();
	factories.insert(entry);

	entry.first = "UNDO";
    entry.second = new OpeUNDO();
	factories.insert(entry);

    entry.first = "NUM";
    entry.second = new OpeNUM();
    factories.insert(entry);

    entry.first = "DEN";
    entry.second = new OpeDEN();
    factories.insert(entry);

    entry.first = "POW";
    entry.second = new OpePOW();
    factories.insert(entry);

    entry.first = "SQRT";
    entry.second = new OpeSQRT();
    factories.insert(entry);

    entry.first = "SIN";
    entry.second = new OpeSIN();
    factories.insert(entry);

    entry.first = "COS";
    entry.second = new OpeCOS();
    factories.insert(entry);

    entry.first = "TAN";
    entry.second = new OpeTAN();
    factories.insert(entry);

    entry.first = "ARCSIN";
    entry.second = new OpeARCSIN();
    factories.insert(entry);

    entry.first = "ARCCOS";
    entry.second = new OpeARCCOS();
    factories.insert(entry);

    entry.first = "ARCTAN";
    entry.second = new OpeARCTAN();
    factories.insert(entry);

    entry.first = "EXP";
    entry.second = new OpeEXP();
    factories.insert(entry);

    entry.first = "LN";
    entry.second = new OpeLN();
    factories.insert(entry);

	return factories;
}

bool OpeFactory::isOpe(std::string ope)
{
    // si c'est un ope alors il y a une entrée avec ce string donc count() > 0
	return getOpeFactories().count(ope) > 0;
}
