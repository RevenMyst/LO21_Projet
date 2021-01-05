//////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> Classe principale qui controle toute les autres </summary>
///
/// <classes> Computer, AtomManager </classes>
///
///////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
#include <map>
#include "Pile.h"
#include <vector>
#include <QObject>
#include <iostream>

class Operand;
/// Stocke les variable et fonction
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
    //recupere une copiel'operande associée au string
    Litteral* getLitteral(const std::string str) const;
    size_t size() const { return atoms.size(); }
    //recupere tout le tableau
    std::map<std::string, Litteral*> getAtoms() const{return atoms;}


};
/// Execute le commande
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
    ~Computer() {
        delete pile;
        delete atomManager;
        for(AtomManager* a : atomHistory){
            delete a;
        }
        for(Pile* p : pileHistory){
            delete p;
        }
    }
public:
	static Computer& getInstance(){
		static Computer instance;
		return instance;
	}
    static std::vector<std::string> parse(std::string str);
	static Operand* createOperand(std::string str);
    Pile* getPile() const{ return pile; }
    AtomManager* getAtomManager() const { return atomManager; }
    void execCommand(std::string str);
	void save();
	void backup();
signals:
    void modifAtom();
    void modifEtat();
    void error(const char* err,std::string);
};
