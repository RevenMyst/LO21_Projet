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

class PlusSimpleAction : public Action {
	//additions simples : int + int, int + reel, reel + int, reel + reel
public:
	PlusSimpleAction() = default;
	Litteral* exec(Litteral* l1, Litteral* l2) override;
};

