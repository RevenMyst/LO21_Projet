#pragma once
#include "Litteral.h"

class LitRational : public Litteral
{
	int numerateur;
	unsigned int denominateur;
	LitType Type = RATIONALLIT;
public:
	int getNum() { return numerateur; }
	unsigned int getDen() { return denominateur; }
};
