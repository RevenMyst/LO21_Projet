#pragma once
#include "Litteral.h"

class LitRational : public LitteralNumerique
{
	int numerateur;
	unsigned int denominateur;
	LitType Type = RATIONALLIT;
public:
	LitRational(int n, unsigned int d) : numerateur(n), denominateur(d) {
		ReductionRational(numerateur, denominateur);
	}
	void ReductionRational(int Num, unsigned int Den);
	int getNum() const { return numerateur; }
	unsigned int getDen() const { return denominateur; }
	double getValue() const;
	std::string toString(int size) const{
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
