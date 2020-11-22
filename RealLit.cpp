#include "LitReel.h"

double LitReel::getValue() {
	//Taille maximale si on a un int de 10 chiffres et une mantisse de 10 chiffres
	int i = 20;
	std::string stringValue = LitReel::toString(i);
	double res = stod(stringValue);
	return(res);
}

std::string LitReel::toString(int size) {
	std::string valeur = std::to_string(integer).append(".");
	std::string virgule = std::to_string(mantisse);
	if (virgule != "0")
		valeur = valeur.append(virgule);
	return(valeur);
}
