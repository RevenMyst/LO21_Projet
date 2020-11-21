#pragma once
#include "Operand.h"

#include <string>
class Operator : public Operand
{
private:
	//verifie quil reste assez d'elements dans la pile pour effectuer l'operation.
	bool verify() {
		int elementDansPile; // a mettre a jour lors de la creation de la pile
		return (arite >= elementDansPile);
	}
protected:
	std::string symbole;
	virtual void ope() = 0;
public:
	void exec() {
		if (verify()) {
			ope();
		}
		else {
			throw "erreur";// a mettre a jour lorsde la creation de la classe Exception
		}
	}

};
