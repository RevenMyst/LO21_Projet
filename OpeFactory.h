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
