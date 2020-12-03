#pragma once
#include <string>
#include <map>
#include "Litteral.h"

class LitFactory {
protected:
	LitFactory() = default;
	virtual ~LitFactory() {}
	virtual Operand* getLitteral() = 0;
	static std::map<std::string, LitFactory*> getLitFactories();
};

class INTFactory : public LitFactory {
public:
	INTFactory() = default;
	Operand* getLitteral() override { return new LitInt(); }
};

class REALFactory : public LitFactory {
public:
	REALFactory() = default;
	Operand* getLitteral() override { return new RealLit(); }
};

class RATFactory : public LitFactory {
public:
	RATFactory() = default;
	Operand* getLitteral(std::string rat);
};

class EXPFactory : public LitFactory {
public:
	EXPFactory() = default;
	Operand* getLitteral() override { return new ExpLit(); }
};

class PROGFactory : public LitFactory {
public:
	PROGFactory() = default;
	Operand* getLitteral() override { return new ProgLit(); }
};

class ATOMFactory : public LitFactory {
public:
	PROGFactory() = default;
	Operand* getLitteral() override { return new Operand(); }
};
