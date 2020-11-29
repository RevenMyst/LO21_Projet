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
		throw ComputerException("Erreur : La Litt�rale entiere est incompatible avec cet operateur"); 
	}
	virtual void visitRealLit(RealLit* lit) const { 
		lit->exec(); 
		throw ComputerException("Erreur : La Litt�rale r�elle est incompatible avec cet operateur"); 
	}
	virtual void visitRationalLit(RationalLit* lit) const { 
		lit->exec(); 
		throw ComputerException("Erreur : La Litt�rale rationnal est incompatible avec cet operateur");
	}
	virtual void visitProgLit(ProgLit* lit) const { 
		lit->exec(); 
		throw ComputerException("Erreur : La Litt�rale programme est incompatible avec cet operateur"); 
	}
	virtual void visitExpLit(ExpLit* lit) const { 
		lit->exec(); 
		throw ComputerException("Erreur : La Litt�rale expression est incompatible avec cet operateur"); 
	}
};