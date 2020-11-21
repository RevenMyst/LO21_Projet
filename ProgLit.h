#pragma once
#include "Litteral.h"
#include <vector>
class ProgLit : public Litteral
{
private:
	std::vector<Operand> operands;
	LitType type = PROGLIT;
public:
	ProgLit() = default;
	void addOperand(Operand o) {
		operands.push_back(o);
	}
	std::string toString(int size) const;
	std::vector<Operand> getOperands() const { return operands; }
	void accept(Visitor vistor) { visitor.visitProgLit(*this); }
};

