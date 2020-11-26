#include "Computer.h"
#include "Operand.h"
#include "Pile.h"


bool AtomManager::addAtom(const std::string str, Operand* o)
{
	std::pair<std::map<std::string, Operand *>::iterator, bool> res = atoms.insert(std::pair<std::string,Operand*>(str, o));
	return res.second;
}

bool AtomManager::removeAtom(const std::string str)
{
	unsigned int res = atoms.erase(str);
	return res != 0;
}

Operand* AtomManager::getOperand(const std::string str)
{
	return nullptr;

}
