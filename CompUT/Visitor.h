#pragma once
#include "ComputerException.h"
#include "Litteral.h"

class Visitor {
public:
	virtual void visitIntLit(IntLit* lit) {
		lit->exec();
		throw ComputerException("Erreur : La Litt�rale entiere est incompatible avec cet operateur");
	}
	virtual void visitRealLit(RealLit* lit) {
		lit->exec();
		throw ComputerException("Erreur : La Litt�rale r�elle est incompatible avec cet operateur");
	}
	virtual void visitRationalLit(RationalLit* lit) {
		lit->exec();
		throw ComputerException("Erreur : La Litt�rale rationnal est incompatible avec cet operateur");
	}
	virtual void visitProgLit(ProgLit* lit) {
		lit->exec();
		throw ComputerException("Erreur : La Litt�rale programme est incompatible avec cet operateur");
	}
	virtual void visitExpLit(ExpLit* lit) {
		lit->exec();
		throw ComputerException("Erreur : La Litt�rale expression est incompatible avec cet operateur");
	}
};
