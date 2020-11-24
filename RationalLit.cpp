#include "RationalLit.h"

void LitRational::ReductionRational(int Num, unsigned int Den) {
	for (int i = Num * Den; i > 1; i--) {
		if ((Den % i == 0) && (Num % i == 0)) {
			Den /= i;
			Num /= i;
		}
	}
}

/*
* L'algorithme getValue prend une forme ainsi suivante:
*	Si on a un Rationel 13/7, le process serà trouver un entier 137 en depilant les chiffres de numerateur
*	et puis les chiffres du denominateur en les stockant dans la valeur value
*/
int LitRational::getValue() const {
	//Conversion a string des parties du reel
	std::string s1 = std::to_string(getNum());
	std::string s2 = std::to_string(getDen());

	//Concatenation des chaines
	std::string s = s1 + s2;

	//Conversion de retour a int pour l'evaluation
	return(stoi(s));
}
