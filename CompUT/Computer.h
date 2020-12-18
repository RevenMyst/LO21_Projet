#pragma once
#include <string>
#include <map>
#include "Pile.h"
#include <vector>
#include <QObject>

class Operand;
class AtomManager : public QObject
{
    Q_OBJECT
private:
	std::map<std::string, Litteral*> atoms;
public:
	AtomManager() = default;
	AtomManager(AtomManager& a);
	~AtomManager();
	bool addAtom(const std::string, Litteral*);
	bool removeAtom(const std::string str);
	Litteral* getLitteral(const std::string str);
    size_t size() { return atoms.size(); }
    std::map<std::string, Litteral*> getAtoms(){return atoms;}
signals:
    void modifAtom();
};

class Computer : public QObject
{
    Q_OBJECT
private:
	std::list<AtomManager*> atomHistory;
	std::list<Pile*> pileHistory;
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
	void execCommand(std::string str);
	void save();
	void backup();
signals:
    void modifEtat();
    void error(const char* err,std::string);
};





