#pragma once
class IntLit;
class ProgLit;
class RealLit;
class RationalLit;
class ExpLit;

class Visitor {
public:
	virtual void visitIntLit(const IntLit* lit) const { throw "error"; }
	virtual void visitRealLit(const RealLit* lit) const { throw "error"; }
	virtual void visitRationalLit(const RationalLit* lit) const { throw "error"; }
	virtual void visitProgLit(const ProgLit* lit) const { throw "error"; }
	virtual void visitExpLit(const ExpLit* lit) const { throw "error"; }
};