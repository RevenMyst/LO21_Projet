#pragma once
#include "Litteral.h"

class LitRational : public Litteral
{
	int numerateur;
	unsigned int denominateur;
	LitType Type = RATIONALLIT;
public:
	LitRational(int n, unsigned int d) : numerateur(n), denominateur(d) {}
	int getNum() { return numerateur; }
	unsigned int getDen() { return denominateur; }
	std::string toString(int size) {
		//Cas d'ou on a un entier
		if (getDen() == 1)
			return(std::to_string(getNum()));
		//Cas d'ou on a meme valeur dans les deux parties ex: 5/5
		if (getDen() == getNum())
			return("1");
		std::string res = std::to_string(getNum()) + "/" + std::to_string(getDen());
		return(res);
	}
};
