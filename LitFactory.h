#pragma once
#include <string>
#include <map>

class Operand;
enum LitType;
class LitFactory {
protected:
	LitFactory() = default;
	virtual ~LitFactory() {}
	virtual Operand* getLitteral(std::string str) = 0;
	static std::map<LitType, LitFactory*> getLitFactories();
};

class INTFactory : public LitFactory {
public:
	INTFactory() = default;
	Operand* getLitteral(std::string str);
};

class REALFactory : public LitFactory {
public:
	REALFactory() = default;
	Operand* getLitteral(std::string str);
};

class RATFactory : public LitFactory {
public:
	RATFactory() = default;
	Operand* getLitteral(std::string str) override;
};

class EXPFactory : public LitFactory {
public:
	EXPFactory() = default;
	Operand* getLitteral(std::string str);
};

class PROGFactory : public LitFactory {
public:
	PROGFactory() = default;
	Operand* getLitteral(std::string str);
};

class ATOMFactory : public LitFactory {
public:
	ATOMFactory() = default;
	Operand* getLitteral(std::string str);
};
