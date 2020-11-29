#include "Computer.h"
#include "Litteral.h"
#include "Pile.h"
#include <stdexcept>
#include <iterator>
#include <sstream>
#include <vector>
using namespace std;

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

vector<string> Computer::parse(std::string str)
{

	istringstream iss(str);
	vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
	vector<string> res;
	int prog = 0;
	string p = "";
	for (int i = 0; i < results.size(); i++) {
		if (results[i] != "[" && prog == 0) {
			res.push_back(results[i]);
		}
		else {
			if (results[i] == "[") {
				p = p + results[i] + " ";
				prog++;
			}
			else if (results[i] == "]") {
				prog--;

				p = p + results[i] + " ";
				if (prog == 0) {
					p = p.substr(0, p.size() - 1);
					p = p.substr(2, p.size() - 4); //pour enlever les crochets
					res.push_back(p);
					p = "";
				}
			}
			else {
				p = p + results[i] + " ";
			}
		}
	}
	return results;
}
