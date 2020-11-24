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
	std::string toString() const;
	std::vector<Operand> getOperands() const { return operands; }
	void accept(Visitor& vistor) const override { visitor.visitProgLit(*this); }
	bool operator==(const Litteral &) const override;
	bool operator!=(const Litteral&) const override;

};

