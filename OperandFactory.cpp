#include "OperandFactory.h"
#include <regex>
#include "OpeFactory.h"

Operand* OperandFactory::createOperand(std::string str)
{
    if (std::regex_match(str, std::regex("[0-9]*"))) {
        //int
    }else 
    if (std::regex_match(str, std::regex("-?[0-9]+/[0-9]+"))) {
        //rationel
    }else
    if (std::regex_match(str, std::regex("-?[0-9]*\\.[0-9]*"))) {
       //reel
    }
    if (std::regex_match(str, std::regex("([A-Z]+[0-9]*)+"))) {
        // Forme d'un atome
        if (OpeFactory::isOpe(str)) {
            //si c'est un op�rateur
            return OpeFactory::getOpeFactories().at(str)->getOpe();
        }
        else {
            //sinon litterale Atome

        }
    }
    else 
    if (std::regex_match(str, std::regex("(\\+|\\-|\\/|=|>=|<=|<|>|!=|\\*)"))) {
        //operateur + - * / <= >= == < > !=
        return OpeFactory::getOpeFactories().at(str)->getOpe();
    }
    else 
    if(str[0]=='['&&str[str.size()-1]==']'){
        
    }else
    if (str[0] == '\'' && str[str.size() - 1] == '\'') {

    }
    return nullptr;
}
