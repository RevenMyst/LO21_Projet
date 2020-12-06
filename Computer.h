#pragma once
#include <string>
#include <map>
#include "Pile.h"
#include <vector>

class Operand;
class AtomManager {
	std::map<std::string, Litteral*> atoms;
public:
	AtomManager() = default;
	bool addAtom(const std::string, Litteral*);
	bool removeAtom(const std::string str);
	Litteral* getLitteral(const std::string str);
	unsigned int size() { return atoms.size(); }
};

class Computer
{
private:
	Pile* pile;
	AtomManager* atomManager;
	Computer() :pile(new Pile()), atomManager(new AtomManager()) {}
	Computer(const Computer& c);
	Computer& operator=(const Computer& c) = default;
	~Computer() { delete pile; }
public:
	static Computer& getInstance(){
		static Computer instance;
		return instance;
	}
	static std::vector<std::string> parse(std::string str);
	static Operand* createOperand(std::string str);
	Pile* getPile() { return pile; }
	AtomManager* getAtomManager() { return atomManager; }
};



