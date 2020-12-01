#pragma once
#include <string>
#include <map>
#include "Litteral.h"

class LitFactory {
protected:
	LitFactory() = default;
	virtual ~LitFactory() {}
	virtual Litteral* getLitteral() = 0;
	static std::map<std::string, LitFactory*> getLitFactories();
	static bool isLit(std::string Lit);
};

class INTFactory : public LitFactory {
public:
	INTFactory() = default;
	Litteral* getLitteral() override { return new LitInt(); }
};

class REALFactory : public LitFactory {
public:
	REALFactory() = default;
	Litteral* getLitteral() override { return new RealLit(); }
};

class RATFactory : public LitFactory {
public:
	RATFactory() = default;
	Litteral* getLitteral() override { return new RationalLit(); }
};

class EXPFactory : public LitFactory {
public:
	EXPFactory() = default;
	Litteral* getLitteral() override { return new ExpLit(); }
};

class PROGFactory : public LitFactory {
public:
	PROGFactory() = default;
	Litteral* getLitteral() override { return new RealLit(); }
};
