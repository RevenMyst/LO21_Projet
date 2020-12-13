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
class PlusSimpleAction : public Action {
	//additions simples : int + int, int + reel, reel + int, reel + reel, reel + rationnel, rationnel + reel
public:
	PlusSimpleAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};


class PlusRatRatAction : public Action {
	//addition : rationnel + rationnel
public:
	PlusRatRatAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

class PlusRatIntAction : public Action {
	//additions : int + rationnel, rationnel + int
public:
	PlusRatIntAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

//Classe Actions Multiplication ----------
class MulSimpleAction : public Action {
	//multiplications simples : int * int, int * reel, reel * int, reel * reel, reel * rationnel, rationnel * reel
public:
	MulSimpleAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

class MulRatRatAction : public Action {
	//multiplication : rationnel * rationnel
public:
	MulRatRatAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};
class MulRatIntAction : public Action {
	//multiplications : int * rationnel, rationnel * int
public:
	MulRatIntAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};


//Classe Soustraction Actions ---
class MoinsSimpleAction : public Action {
	//soustraction simples : int - int, int - reel, reel - int, reel - reel, reel - rationnel, rationnel - reel
public:
	MoinsSimpleAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

class MoinsRatRatAction : public Action {
	//soustraction : rationnel - rationnel
public:
	MoinsRatRatAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

class MoinsRatIntAction : public Action {
	//soustraction: rationnel - int
public:
	MoinsRatIntAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

class MoinsIntRatAction : public Action {
	//soustraction : int - rationnel
public:
	MoinsIntRatAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

//Classe Division Actions ---
class DivisionSimpleAction : public Action {
	//division simples : int - int, int - reel, reel - int, reel - reel, reel - rationnel, rationnel - reel
public:
	DivisionSimpleAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

class DivisionRatRatAction : public Action {
	//division : rationnel - rationnel
public:
	DivisionRatRatAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

class DivisionRatIntAction : public Action {
	//division: rationnel - int
public:
	DivisionRatIntAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

class DivisionIntRatAction : public Action {
	//division : int - rationnel
public:
	DivisionIntRatAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

