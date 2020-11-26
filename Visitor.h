#pragma once
#include "ComputerException.h"


class IntLit;
class ProgLit;
class RealLit;
class RationalLit;
class ExpLit;

class Visitor {
public:
	virtual void visitIntLit(const IntLit* lit) const { throw ComputerException("Erreur : La Litt�rale entiere est incompatible avec cet operateur"); }
	virtual void visitRealLit(const RealLit* lit) const { throw ComputerException("Erreur : La Litt�rale r�elle est incompatible avec cet operateur"); }
	virtual void visitRationalLit(const RationalLit* lit) const { throw ComputerException("Erreur : La Litt�rale rationnal est incompatible avec cet operateur"); }
	virtual void visitProgLit(const ProgLit* lit) const { throw ComputerException("Erreur : La Litt�rale programme est incompatible avec cet operateur"); }
	virtual void visitExpLit(const ExpLit* lit) const { throw ComputerException("Erreur : La Litt�rale expression est incompatible avec cet operateur"); }
};