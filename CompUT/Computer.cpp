#include "Computer.h"
#include "Litteral.h"
#include "Pile.h"
#include <stdexcept>
#include <iterator>
#include <sstream>
#include <vector>
#include "OpeFactory.h"
#include "LitFactory.h"
#include <regex>
#include "Operand.h"
using namespace std;

AtomManager::AtomManager(AtomManager& a)
{
	for (auto atom : a.atoms) {
		pair<string, Litteral*> entry = pair<string, Litteral*>(atom.first, dynamic_cast<Litteral*>(atom.second->clone()));
		atoms.insert(entry);
	}
}

AtomManager::~AtomManager()
{
	for (auto a : atoms) {
		delete a.second;
	}
}

bool AtomManager::addAtom(const string str, Litteral* o)
{
	if (atoms.count(str) > 0) {
		removeAtom(str);
	}
	pair<map<string, Litteral*>::iterator, bool> res = atoms.insert(pair<string, Litteral*>(str, o));
	return res.second;
}

bool AtomManager::removeAtom(const string str)
{
	unsigned int res = atoms.erase(str);
	return res != 0;
}

Litteral* AtomManager::getLitteral(const string str)
{
	try {
		return dynamic_cast<Litteral*>(atoms.at(str)->clone());
	}
	catch (std::exception e) {
		return nullptr;
	}

}

vector<string> Computer::parse(string str)
{

	istringstream iss(str);
	vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
	vector<string> res;
	int prog = 0;
	string p = "";
	for (size_t i = 0; i < results.size(); i++) {
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
					//p = p.substr(2, p.size() - 4); //pour enlever les crochets
					res.push_back(p);
					p = "";
				}
			}
			else {
				p = p + results[i] + " ";
			}
		}
	}
	return res;
}

Operand* Computer::createOperand(string str)
{
	if (OpeFactory::isOpe(str)) {
		return OpeFactory::getOpeFactories().at(str)->getOpe();
	}
	else {
		//c'est une litterale
		for (LitFactory* l : LitFactory::getLitFactories()) {
			//l.isTypeLit retourne true si le string correcpond a l'expression d'une litteral (regex)
			if (l->isTypeLit(str)) {
				// getLitteral retourne la litteral créée a partir du string
				return l->getLitteral(str);
			}
		}
	}
	// si rien ne correspond au string on retourne une erreur
	throw ComputerException("Erreur : Aucune Operand ne peut etre créée");
}

void Computer::execCommand(std::string command)
{
	//on parse la command pour separer chaque string de chaque operand
	vector<string> opeStringTab = parse(command);
	for (string opeStr : opeStringTab) {
		//on creer chaque operand à partir de son string
		Operand* o = createOperand(opeStr);
		//on sauvegarde l'etat
		save();
		//on exec (empilement si litteral , depilement et calcul si operateur)
		o->exec();
	}
}

void Computer::save()
{
	atomHistory.push_back(new AtomManager(*atomManager));
	pileHistory.push_back(new Pile(*pile));
	if (pileHistory.size() >= 10) {
		pileHistory.pop_front();
		atomHistory.pop_front();
	}
}

void Computer::backup()
{
	if (pileHistory.size() > 1) {
		Pile* temp = pile;
		//on supprime la sauvegarde pre-UNDO
		pileHistory.pop_back();
		//on retablit la sauvegarde
		pile = pileHistory.back();
		//on supprime de la liste
		pileHistory.pop_back();
		delete temp;
	}
	
}






