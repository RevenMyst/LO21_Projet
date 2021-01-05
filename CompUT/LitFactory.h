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
/// superclass des factory de Litterale
class LitFactory {
public:
	LitFactory() = default;
	virtual ~LitFactory() {}
	virtual Operand* getLitteral(std::string str) = 0;
	virtual bool isTypeLit(std::string str) = 0;
	static std::vector<LitFactory*> getLitFactories();
};
/// Factory de la Litterale entiere IntLit
class INTFactory : public LitFactory {
public:
	INTFactory() = default;
	bool isTypeLit(std::string str);
	Operand* getLitteral(std::string str);
};
/// Factory de la Litteral reel RealLit
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
/// Factory de la Litteral expression ExpLit
class ExpressionFactory : public LitFactory {
public:
    ExpressionFactory() = default;
	bool isTypeLit(std::string str);
	Operand* getLitteral(std::string str);
};
/// Factory de la Litteral programme ProgLit
class PROGFactory : public LitFactory {
public:
	PROGFactory() = default;
	bool isTypeLit(std::string str);
	Operand* getLitteral(std::string str);
};
/// Factory de la Litterale atome AtomLit
class ATOMFactory : public LitFactory {
public:
	ATOMFactory() = default;
	bool isTypeLit(std::string str);
	Operand* getLitteral(std::string str);
};
