#include "LitReel.h"

double LitReel::getValue() {
	std::string valeur = std::to_string(integer).append(".");
	std::string virgule = std::to_string(mantisse);
	if (virgule != "0")
		valeur = valeur.append(virgule);
	double res = stod(valeur);
	return(res);
}
