#include "Computer.h"
#include "Litteral.h"
#include "Pile.h"
#include <stdexcept>


bool AtomManager::addAtom(const std::string str, Litteral* o)
{
	if (atoms.count(str) > 0) {
		removeAtom(str);
	}
	std::pair<std::map<std::string, Litteral*>::iterator, bool> res = atoms.insert(std::pair<std::string, Litteral*>(str, o));
	return res.second;
}

bool AtomManager::removeAtom(const std::string str)
{
	unsigned int res = atoms.erase(str);
	return res != 0;
}

Litteral* AtomManager::getLitteral(const std::string str)
{
	try {
		return dynamic_cast<Litteral*>(atoms.at(str)->clone());
	}
	catch (std::exception e) {
		return nullptr;
	}

}
