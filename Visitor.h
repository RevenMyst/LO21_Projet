#pragma once
#include "ComputerException.h"


class IntLit;
class ProgLit;
class RealLit;
class RationalLit;
class ExpLit;

class Visitor {
public:
	virtual void visitIntLit(IntLit* lit) const { 
		lit->exec(); 
		throw ComputerException("Erreur : La Littérale entiere est incompatible avec cet operateur"); 
	}
	virtual void visitRealLit(RealLit* lit) const { 
		lit->exec(); 
		throw ComputerException("Erreur : La Littérale réelle est incompatible avec cet operateur"); 
	}
	virtual void visitRationalLit(RationalLit* lit) const { 
		lit->exec(); 
		throw ComputerException("Erreur : La Littérale rationnal est incompatible avec cet operateur");
	}
	virtual void visitProgLit(ProgLit* lit) const { 
		lit->exec(); 
		throw ComputerException("Erreur : La Littérale programme est incompatible avec cet operateur"); 
	}
	virtual void visitExpLit(ExpLit* lit) const { 
		lit->exec(); 
		throw ComputerException("Erreur : La Littérale expression est incompatible avec cet operateur"); 
	}
};