#pragma once
#include <string>
#include <map>
#include "Pile.h";
class Computer
{
private:
	Pile* pile;
	Computer() :pile(new Pile()) {}
	Computer(const Computer& c);
	Computer& operator=(const Computer& c) = default;
	~Computer() { delete pile; }
public:
	static Computer& getInstance(){
		static Computer instance;
		return instance;
	}
	Pile* getPile() { return pile; }
};

class Operand;

class AtomManager {
	std::map<std::string, Operand*> atoms;
public:
	bool addAtom(const std::string, Operand*);
	bool removeAtom(const std::string str);
	Operand* getOperand(const std::string str);
	unsigned int size() { return atoms.size(); }
};

