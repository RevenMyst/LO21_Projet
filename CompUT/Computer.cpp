#include "Computer.h"
#include "Litteral.h"
#include "Pile.h"
#include <stdexcept>
#include <iterator>
#include <sstream>
#include <iostream>
#include <vector>
#include "OpeFactory.h"
#include "LitFactory.h"
#include <regex>
#include "Operand.h"
using namespace std;


/**********************
 *****AtomManager******
 **********************/
AtomManager::AtomManager(AtomManager& a)
{
    for (auto atom : a.atoms) {
        pair<string, Litteral*> entry = pair<string, Litteral*>(atom.first, dynamic_cast<Litteral*>(atom.second->clone()));
        atoms.insert(entry);
    }
}

AtomManager::~AtomManager()
{
    //il faut detruire l'operande stockée
    for (auto a : atoms) {
        delete a.second;
    }
}

bool AtomManager::addAtom(const string str, Litteral* o)
{
    // si il existe deja, on le supprime
    if (atoms.count(str) > 0) {
        removeAtom(str);
    }
    pair<map<string, Litteral*>::iterator, bool> res = atoms.insert(pair<string, Litteral*>(str, o));

    Computer::getInstance().modifAtom();
    return res.second;
}

bool AtomManager::removeAtom(const string str)
{
    if (atoms.count(str) > 0) {
        //il faut supprimer l'operande stockée
        delete atoms.at(str);
    }
    size_t res = atoms.erase(str);
    Computer::getInstance().modifAtom();
    return res != 0;
}

Litteral* AtomManager::getLitteral(const string str) const
{
    //si n'existe pas retourne nullptr
    try {
        return dynamic_cast<Litteral*>(atoms.at(str)->clone());
    }
    catch (std::exception &e) {

        return nullptr;
    }

}
/**********************
 *******Computer*******
 **********************/
vector<string> Computer::parse(string str)
{

    istringstream iss(str);
    // on separe les strings par les espaces
    vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
    vector<string> res;
    //il faut reassembler les litterales programmes
    //profondeur de la litterales programmes
    int prog = 0;
    string p = "";
    for (size_t i = 0; i < results.size(); i++) {
        // si ce n'est pas un element de ProgLit on ajoute simplement dans res
        if (results[i] != "[" && prog == 0) {
            res.push_back(results[i]);
        }
        else {
            //si c'est [ on commence a creer le string de la Proglit plus incremente la profondeur
            if (results[i] == "[") {
                p = p + results[i] + " ";
                prog++;
            }
            else if (results[i] == "]") {
                // si c'est ] on decremente la profondeur
                prog--;

                p = p + results[i] + " ";
                if (prog == 0) {
                    //si profondeur = 0 on a finit de reconstruire la ProgLit
                    p = p.substr(0, p.size() - 1);
                    //p = p.substr(2, p.size() - 4); //pour enlever les crochets
                    res.push_back(p);
                    p = "";
                }
            }
            //sinon on ajoute a la ProgLit courante
            else {
                p = p + results[i] + " ";
            }
        }
    }
    //on retourne le nouveau tableau
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
                // getLitteral retourne la litteral cr��e a partir du string
                return l->getLitteral(str);
            }
        }
    }
    // si rien ne correspond au string on retourne une erreur
    throw ComputerException("Erreur : Aucune Operande ne peut etre créée");
}

void Computer::execCommand(std::string command)
{
    //on parse la command pour separer chaque string de chaque operand
    vector<string> opeStringTab = parse(command);
    for (size_t i = 0; i< opeStringTab.size();i++) {
        try {

            //on creer chaque operand � partir de son string
            Operand* o = createOperand(opeStringTab[i]);

            //on sauvegarde l'etat
            save();
            //on exec (empilement si litteral , depilement et calcul si operateur)
            o->exec();
            modifEtat();

        }  catch (exception& e) {
            string restCom = "";
            for(;i< opeStringTab.size();i++){
                restCom.append(opeStringTab[i]+" ");
            }
            error(e.what(),restCom);
        }

    }
}

void Computer::save()
{
    atomHistory.push_back(new AtomManager(*atomManager));
    pileHistory.push_back(new Pile(*pile));
    if (pileHistory.size() >= 10) {
        //si plus de 10 elements on supprimes les derniers pour economiser de l'espace
        pileHistory.pop_front();
        atomHistory.pop_front();
    }
}

void Computer::backup()
{
    if (pileHistory.size() > 1) {

        Pile* tempPile = pile;
        AtomManager* tempAtom = atomManager;
        //on supprime la sauvegarde pre-UNDO
        delete pileHistory.back();
        pileHistory.pop_back();
        delete atomHistory.back();
        atomHistory.pop_back();
        //on retablit la sauvegarde
        pile = pileHistory.back();
        atomManager = atomHistory.back();
        //on supprime de la liste
        pileHistory.pop_back();
        atomHistory.pop_back();
        delete tempPile;
        delete tempAtom;
        modifAtom();
    }

}
