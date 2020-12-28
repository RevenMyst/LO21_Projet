//////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> Definit Visitor pour mettre en place le DP Visitor </summary>
///
/// <classes> Visitor </classes>
///
///////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "ComputerException.h"
#include "Litteral.h"

class Visitor {
public:
	virtual void visitIntLit(IntLit* lit) {
		lit->exec();
        throw ComputerException("Erreur : La Litterale entiere est incompatible avec cet operateur");
	}
	virtual void visitRealLit(RealLit* lit) {
		lit->exec();
        throw ComputerException("Erreur : La Litterale reelle est incompatible avec cet operateur");
	}
	virtual void visitRationalLit(RationalLit* lit) {
		lit->exec();
        throw ComputerException("Erreur : La Litterale rationnal est incompatible avec cet operateur");
	}
	virtual void visitProgLit(ProgLit* lit) {
		lit->exec();
        throw ComputerException("Erreur : La Litterale programme est incompatible avec cet operateur");
	}
	virtual void visitExpLit(ExpLit* lit) {
		lit->exec();
        throw ComputerException("Erreur : La Litterale expression est incompatible avec cet operateur");
	}
};
