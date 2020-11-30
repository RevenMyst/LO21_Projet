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
