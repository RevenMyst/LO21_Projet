#pragma once
#include "Litteral.h"
#include <string>
#include "ComputerException.h"
class Operator : public Operand
{
private:

	bool verify() {
		
		return (arite <= Computer::getInstance().getPile()->size());
	}
protected:
	std::string symbole;
	virtual void ope() = 0;
public:
	std::string toString() const { return symbole; }
	void exec() {
		if (verify()) {
			ope();
			delete this;
		}
		else {
			throw ComputerException("Erreur : Il n'y a pas assez de Litterals dans la pile.");
		}
	}

};

class OpeDUP : public Operator {
	unsigned int arite = 1;
	std::string symbole = "DUP";
public:
	OpeDUP() = default;
	void ope() override;
	Operand* clone() { return new OpeDUP(*this); }
};
