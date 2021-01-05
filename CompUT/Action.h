//////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> Definit le comportement d'un operateur binaire pour 2 types de litterales donnee </summary>
///
/// <classes> Action et ses sous classe </classes>
///
///////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <map>
#include <tuple>
#include <string>
#include "Litteral.h"

using namespace std;

class Litteral;

class Action
{
public:
	virtual Litteral* exec(Litteral* l1, Litteral* l2) = 0;
	static map<tuple<string, LitType, LitType>, Action*> getActions();
	static bool exist(tuple<string, LitType, LitType> t);
};

// Classe Addition Actions -----------

///additions simples : int + int, int + reel, reel + int, reel + reel, reel + rationnel, rationnel + reel
class PlusSimpleAction : public Action {
public:
	PlusSimpleAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};


///addition : rationnel + rationnel
class PlusRatRatAction : public Action {
public:
	PlusRatRatAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

///additions : int + rationnel, rationnel + int
class PlusRatIntAction : public Action {
public:
	PlusRatIntAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

//Classe Actions Multiplication ----------

///multiplications simples : int * int, int * reel, reel * int, reel * reel, reel * rationnel, rationnel * reel
class MulSimpleAction : public Action {
public:
	MulSimpleAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

///multiplication : rationnel * rationnel
class MulRatRatAction : public Action {
public:
	MulRatRatAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

///multiplications : int * rationnel, rationnel * int
class MulRatIntAction : public Action {
public:
	MulRatIntAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};


//Classe Soustraction Actions ---

///soustraction simples : int - int, int - reel, reel - int, reel - reel, reel - rationnel, rationnel - reel
class MoinsSimpleAction : public Action {
public:
	MoinsSimpleAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

///soustraction : rationnel - rationnel
class MoinsRatRatAction : public Action {
public:
	MoinsRatRatAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

///soustraction: rationnel - int
class MoinsRatIntAction : public Action {
public:
	MoinsRatIntAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

///soustraction : int - rationnel
class MoinsIntRatAction : public Action {
public:
	MoinsIntRatAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

//Classe Division Actions ---

///division simples : int / int, int / reel, reel / int, reel / reel, reel / rationnel, rationnel / reel
class DivisionSimpleAction : public Action {
public:
	DivisionSimpleAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

///division : rationnel / rationnel
class DivisionRatRatAction : public Action {
public:
	DivisionRatRatAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

///division: rationnel / int
class DivisionRatIntAction : public Action {
public:
	DivisionRatIntAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

///division : int / rationnel
class DivisionIntRatAction : public Action {
public:
	DivisionIntRatAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

///division : int / int
class DivisionIntIntAction : public Action {
public:
	DivisionIntIntAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};


//Classe Puissance Actions ---

///Puissance : Int^Rationnel, Real^Rationnel, Int^Real, Real^Real, Real^Int
class POWSimpleAction : public Action {
public:
	POWSimpleAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};


///Puissance: int ^ int
class POWIntIntAction : public Action {
public:
	POWIntIntAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

///Puissance: Rationnel ^ int
class POWRatIntAction : public Action {
public:
	POWRatIntAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

///Puissance: Rationnel ^ Rationnel, Rationnal^Real
class POWRatRatRatRealAction : public Action {
public:
	POWRatRatRatRealAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};
