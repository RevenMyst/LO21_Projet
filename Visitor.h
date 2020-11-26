#pragma once
#include "ComputerException.h"


class IntLit;
class ProgLit;
class RealLit;
class RationalLit;
class ExpLit;

class Visitor {
public:
	virtual void visitIntLit(const IntLit* lit) const { throw ComputerException("Erreur : La Littérale entiere est incompatible avec cet operateur"); }
	virtual void visitRealLit(const RealLit* lit) const { throw ComputerException("Erreur : La Littérale réelle est incompatible avec cet operateur"); }
	virtual void visitRationalLit(const RationalLit* lit) const { throw ComputerException("Erreur : La Littérale rationnal est incompatible avec cet operateur"); }
	virtual void visitProgLit(const ProgLit* lit) const { throw ComputerException("Erreur : La Littérale programme est incompatible avec cet operateur"); }
	virtual void visitExpLit(const ExpLit* lit) const { throw ComputerException("Erreur : La Littérale expression est incompatible avec cet operateur"); }
};