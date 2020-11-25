#pragma once
#include "ComputerException.h"
class IntLit;
class ProgLit;
class RealLit;
class RationalLit;
class ExpLit;

class Visitor {
public:
	virtual void visitIntLit(const IntLit* lit) const { throw ComputerException("Erreur : cette littérale est incompatible avec cet operateur"); }
	virtual void visitRealLit(const RealLit* lit) const { throw ComputerException("Erreur : cette littérale est incompatible avec cet operateur"); }
	virtual void visitRationalLit(const RationalLit* lit) const { throw ComputerException("Erreur : cette littérale est incompatible avec cet operateur"); }
	virtual void visitProgLit(const ProgLit* lit) const { throw ComputerException("Erreur : cette littérale est incompatible avec cet operateur"); }
	virtual void visitExpLit(const ExpLit* lit) const { throw ComputerException("Erreur : cette littérale est incompatible avec cet operateur"); }
};