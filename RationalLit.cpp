#include "RationalLit.h"

void LitRational::ReductionRational(int Num, unsigned int Den) {
	for (int i = Num * Den; i > 1; i--) {
		if ((Den % i == 0) && (Num % i == 0)) {
			Den /= i;
			Num /= i;
		}
	}
}

double LitRational::getValue() const {
	int Num = getNum();
	int Dem = getDen();
	double Res = Num/Den;
	return(Res);
}
