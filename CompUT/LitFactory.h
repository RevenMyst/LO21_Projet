//////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> Definit les methodes reconnaitre et construire les litterales </summary>
///
/// <classes> ComputerException </classes>
///
///////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
#include <vector>

class Operand;
class LitFactory {
public:
	LitFactory() = default;
	virtual ~LitFactory() {}
	virtual Operand* getLitteral(std::string str) = 0;
	virtual bool isTypeLit(std::string str) = 0;
	static std::vector<LitFactory*> getLitFactories();
};

class INTFactory : public LitFactory {
public:
	INTFactory() = default;
	bool isTypeLit(std::string str);
	Operand* getLitteral(std::string str);
};

class REALFactory : public LitFactory {
public:
	REALFactory() = default;
	bool isTypeLit(std::string str);
	Operand* getLitteral(std::string str);
};
/*** non utilisé
class RATFactory : public LitFactory {
public:
	RATFactory() = default;
	bool isTypeLit(std::string str);
	Operand* getLitteral(std::string str);
};
***/
class ExpressionFactory : public LitFactory {
public:
    ExpressionFactory() = default;
	bool isTypeLit(std::string str);
	Operand* getLitteral(std::string str);
};

class PROGFactory : public LitFactory {
public:
	PROGFactory() = default;
	bool isTypeLit(std::string str);
	Operand* getLitteral(std::string str);
};

class ATOMFactory : public LitFactory {
public:
	ATOMFactory() = default;
	bool isTypeLit(std::string str);
	Operand* getLitteral(std::string str);
};
