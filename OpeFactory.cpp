#include "OpeFactory.h"

std::map<std::string, OpeFactory*> OpeFactory::getOpeFactories()
{
	std::map<std::string, OpeFactory*>factories;
	std::pair<std::string, OpeFactory*> entry;

	entry.first = "DUP";
	entry.second = new DUPFactory();
	factories.insert(entry);

	entry.first = "DROP";
	entry.second = new DROPFactory();
	factories.insert(entry);

	entry.first = "SWAP";
	entry.second = new SWAPFactory();
	factories.insert(entry);

	entry.first = "CLEAR";
	entry.second = new CLEARFactory();
	factories.insert(entry);

	entry.first = "STO";
	entry.second = new STOFactory();
	factories.insert(entry);

	entry.first = "FORGET";
	entry.second = new FORGETFactory();
	factories.insert(entry);

	entry.first = "EVAL";
	entry.second = new EVALFactory();
	factories.insert(entry);

	entry.first = "AND";
	entry.second = new ANDFactory();
	factories.insert(entry);

	entry.first = "OR";
	entry.second = new ORFactory();
	factories.insert(entry);

	entry.first = "+";
	entry.second = new PLUSFactory();
	factories.insert(entry);

	entry.first = "-";
	entry.second = new MOINSFactory();
	factories.insert(entry);

	entry.first = "*";
	entry.second = new MULFactory();
	factories.insert(entry);

	entry.first = "/";
	entry.second = new DIVFactory();
	factories.insert(entry);

	entry.first = "=";
	entry.second = new EQUALFactory();
	factories.insert(entry);

	entry.first = "!=";
	entry.second = new DIFFactory();
	factories.insert(entry);

	entry.first = ">";
	entry.second = new GTFactory();
	factories.insert(entry);

	entry.first = "<";
	entry.second = new LTFactory();
	factories.insert(entry);

	entry.first = ">=";
	entry.second = new GTEFactory();
	factories.insert(entry);

	entry.first = "<=";
	entry.second = new LTEFactory();
	factories.insert(entry);

	entry.first = "DIV";
	entry.second = new DIVFactory();
	factories.insert(entry);

	entry.first = "MOD";
	entry.second = new MODFactory();
	factories.insert(entry);

	entry.first = "IFT";
	entry.second = new IFTFactory();
	factories.insert(entry);

	entry.first = "IFTE";
	entry.second = new IFTEFactory();
	factories.insert(entry);

    entry.first = "WHILE";
    entry.second = new WHILEFactory();
    factories.insert(entry);

	entry.first = "NOT";
	entry.second = new NOTFactory();
	factories.insert(entry);

	entry.first = "NEG";
	entry.second = new NEGFactory();
	factories.insert(entry);

	entry.first = "UNDO";
	entry.second = new UNDOFactory();
	factories.insert(entry);

    entry.first = "NUM";
    entry.second = new NUMFactory();
    factories.insert(entry);

    entry.first = "DEN";
    entry.second = new DENFactory();
    factories.insert(entry);

    entry.first = "POW";
    entry.second = new POWFactory();
    factories.insert(entry);

    entry.first = "SQRT";
    entry.second = new SQRTFactory();
    factories.insert(entry);

    entry.first = "SIN";
    entry.second = new SINFactory();
    factories.insert(entry);

    entry.first = "COS";
    entry.second = new COSFactory();
    factories.insert(entry);

    entry.first = "TAN";
    entry.second = new TANFactory();
    factories.insert(entry);

    entry.first = "ARCSIN";
    entry.second = new ARCSINFactory();
    factories.insert(entry);

    entry.first = "ARCCOS";
    entry.second = new ARCCOSFactory();
    factories.insert(entry);

    entry.first = "ARCTAN";
    entry.second = new ARCTANFactory();
    factories.insert(entry);

	return factories;
}

bool OpeFactory::isOpe(std::string ope)
{
	return getOpeFactories().count(ope) > 0;
}
