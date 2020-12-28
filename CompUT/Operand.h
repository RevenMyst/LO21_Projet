//////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> Definit la classe mere de tous les elements : Litterales et Operateurs </summary>
///
/// <classes> Operand </classes>
///
///////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>

class Operand
{
public:
	virtual std::string toString() const= 0;
    virtual void exec() = 0;
	virtual Operand* clone() = 0;
    virtual ~Operand()= default;

};
