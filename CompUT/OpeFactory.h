//////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> Definit comment reconnaitre un operateur et le construire </summary>
///
/// <classes> opeFactory </classes>
///
///////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <map>
#include <string>
#include "Operator.h"
class OpeFactory
{
public:
	OpeFactory() = default;
    virtual ~OpeFactory() {}
    //recupere toutes les Operateurs
    static std::map<std::string, Operator*> getOpeFactories();
    // pour savoir si string correspond operator
	static bool isOpe(std::string ope);
};


