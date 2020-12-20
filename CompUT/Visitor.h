#pragma once
#include "ComputerException.h"
#include "Litteral.h"

class Visitor {
public:
	virtual void visitIntLit(IntLit* lit) { 
		lit->exec(); 
		throw ComputerException("Erreur : La Littérale entiere est incompatible avec cet operateur"); 
	}
	virtual void visitRealLit(RealLit* lit) { 
		lit->exec(); 
		throw ComputerException("Erreur : La Littérale réelle est incompatible avec cet operateur"); 
	}
	virtual void visitRationalLit(RationalLit* lit) { 
		lit->exec(); 
		throw ComputerException("Erreur : La Littérale rationnal est incompatible avec cet operateur");
	}
	virtual void visitProgLit(ProgLit* lit) { 
		lit->exec(); 
		throw ComputerException("Erreur : La Littérale programme est incompatible avec cet operateur"); 
	}
	virtual void visitExpLit(ExpLit* lit) { 
		lit->exec(); 
		throw ComputerException("Erreur : La Littérale expression est incompatible avec cet operateur"); 
	}
};