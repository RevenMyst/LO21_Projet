#pragma once
#include "Operand.h"
#include <string>
#include "ComputerException.h"
class Operator : public Operand
{
private:

	bool verify() {
		
		return (arite >= Computer::getInstance().getPile()->size());
	}
protected:
	std::string symbole;
	virtual void ope() = 0;
public:
	std::string toString() const { return symbole; }
	void exec() {
		if (verify()) {
			ope();
		}
		else {
			throw ComputerException("Erreur : Il n'y a pas assez de Litterals dans la pile.");
		}
	}

};
