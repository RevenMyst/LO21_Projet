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

