#include "RealLit.h"

double LitReel::getValueR() {
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

int LitReel::getValue() {
	//Conversion a string des parties du reel
	std::string s1 = std::to_string(getInt());
	std::string s2 = std::to_string(getMant());

	//Concatenation des chaines
	std::string s = s1 + s2;

	//Conversion de retour a int pour l'evaluation
	return(stoi(s));
}
