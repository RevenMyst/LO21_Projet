#pragma once
#include <map>
#include <string>
#include "Operator.h"
class OpeFactory
{
public:
	OpeFactory() = default;
	virtual ~OpeFactory() {}
	virtual Operator* getOpe() = 0;
	static std::map<std::string, OpeFactory*> getOpeFactories();
	static bool isOpe(std::string ope);
};

class DUPFactory : public OpeFactory {
public:
	DUPFactory() = default;
	Operator* getOpe() override { return new OpeDUP(); }
 };

class SWAPFactory : public OpeFactory {
public:
	SWAPFactory() = default;
	Operator* getOpe() override { return new OpeSWAP(); }
};

class CLEARFactory : public OpeFactory {
public:
	CLEARFactory() = default;
	Operator* getOpe() override { return new OpeCLEAR(); }
};

class DROPFactory : public OpeFactory {
public:
	DROPFactory() = default;
	Operator* getOpe() override { return new OpeDROP(); }
};

class STOFactory : public OpeFactory {
public:
	STOFactory() = default;
	Operator* getOpe() override { return new OpeSTO(); }
};

class FORGETFactory : public OpeFactory {
public:
	FORGETFactory() = default;
	Operator* getOpe() override { return new OpeFORGET(); }
};

class EVALFactory : public OpeFactory {
public:
	EVALFactory() = default;
	Operator* getOpe() override { return new OpeEVAL(); }
};

class ANDFactory : public OpeFactory {
public:
	ANDFactory() = default;
	Operator* getOpe() override { return new OpeAND(); }
};

class ORFactory : public OpeFactory {
public:
	ORFactory() = default;
	Operator* getOpe() override { return new OpeOR(); }
};

class EQUALFactory : public OpeFactory {
public:
	EQUALFactory() = default;
	Operator* getOpe() override { return new OpeEQUAL(); }
};

class DIFFactory : public OpeFactory {
public:
	DIFFactory() = default;
	Operator* getOpe() override { return new OpeDIF(); }
};

class LTFactory : public OpeFactory {
public:
	LTFactory() = default;
	Operator* getOpe() override { return new OpeLT(); }
};

class LTEFactory : public OpeFactory {
public:
	LTEFactory() = default;
	Operator* getOpe() override { return new OpeLTE(); }
};

class GTFactory : public OpeFactory {
public:
	GTFactory() = default;
	Operator* getOpe() override { return new OpeGT(); }
};

class GTEFactory : public OpeFactory {
public:
	GTEFactory() = default;
	Operator* getOpe() override { return new OpeGTE(); }
};

class DIVFactory : public OpeFactory {
public:
	DIVFactory() = default;
	Operator* getOpe() override { return new OpeDIV(); }
};

class MODFactory : public OpeFactory {
public:
	MODFactory() = default;
	Operator* getOpe() override { return new OpeMOD(); }
};

class IFTFactory : public OpeFactory {
public:
	IFTFactory() = default;
	Operator* getOpe() override { return new OpeIFT(); }
};

class IFTEFactory : public OpeFactory {
public:
	IFTEFactory() = default;
	Operator* getOpe() override { return new OpeIFTE(); }
};

class WHILEFactory: public OpeFactory {
public:
    WHILEFactory() = default;
    Operator * getOpe() override { return new OpeWHILE(); }
};

class NOTFactory: public OpeFactory {
public:
    NOTFactory() = default;
    Operator* getOpe() override { return new OpeNOT(); }
};

class NEGFactory: public OpeFactory {
public:
    NEGFactory() = default;
    Operator* getOpe() override { return new OpeNEG(); }
};

class UNDOFactory : public OpeFactory {
public:
	UNDOFactory() = default;
	Operator* getOpe() override { return new OpeUNDO(); }
};

class PLUSFactory : public OpeFactory {
public:
    PLUSFactory() = default;
    Operator * getOpe() override {return new OpePlus();}
};

class MOINSFactory : public OpeFactory {
public:
    MOINSFactory() = default;
    Operator * getOpe() override {return new OpeMoins();}
};

class MULFactory : public OpeFactory {
public:
    MULFactory() = default;
    Operator * getOpe() override {return new OpeMul();}
};

class DIVISIONFactory : public OpeFactory {
public:
    DIVISIONFactory() = default;
    Operator * getOpe() override {return new OpeDivision();}

};

class NUMFactory: public OpeFactory {
public:
    NUMFactory() = default;
    Operator* getOpe() override { return new OpeNUM(); }
};

class DENFactory: public OpeFactory {
public:
    DENFactory() = default;
    Operator* getOpe() override { return new OpeDEN(); }
};

class POWFactory: public OpeFactory {
public:
    POWFactory() = default;
    Operator * getOpe() override { return new OpePOW(); }
};

class SQRTFactory: public OpeFactory {
public:
    SQRTFactory() = default;
    Operator * getOpe() override { return new OpeSQRT(); }
};

class SINFactory: public OpeFactory {
public:
    SINFactory() = default;
    Operator * getOpe() override { return new OpeSIN(); }
};

class COSFactory: public OpeFactory {
public:
    COSFactory() = default;
    Operator * getOpe() override { return new OpeCOS(); }
};

class TANFactory: public OpeFactory {
public:
    TANFactory() = default;
    Operator * getOpe() override { return new OpeTAN(); }
};
