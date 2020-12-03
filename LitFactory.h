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
	Operand* getLitteral(std::string rat);
};

class REALFactory : public LitFactory {
public:
	REALFactory() = default;
	Operand* getLitteral(std::string rat);
};

class RATFactory : public LitFactory {
public:
	RATFactory() = default;
	Operand* getLitteral(std::string rat);
};

class EXPFactory : public LitFactory {
public:
	EXPFactory() = default;
	Operand* getLitteral(std::string rat);
};

class PROGFactory : public LitFactory {
public:
	PROGFactory() = default;
	Operand* getLitteral(std::string rat);
};

class ATOMFactory : public LitFactory {
public:
	PROGFactory() = default;
	Operand* getLitteral(std::string rat);
};
