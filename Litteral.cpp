#include "Litteral.h"


bool operator == (const Litteral& Lit1, const Litteral& Lit2)
{
	bool res = false;
	if (Lit1.getClass() == Lit2.getClass() && dynamic_cast<const LitteralNumerique&>(Lit1).getValue() == dynamic_cast<const LitteralNumerique&>(Lit2).getValue())
		return true;
	return(res);
}

bool operator != (const Litteral& Lit1, const Litteral& Lit2)
{
	bool res = false;
	if (Lit1.getClass() == Lit2.getClass() && dynamic_cast<const LitteralNumerique&>(Lit1).getValue() != dynamic_cast<const LitteralNumerique&>(Lit2).getValue())
		return true;
	return(res);
}

bool operator >= (const Litteral& Lit1, const Litteral& Lit2)
{
	bool res = false;
	if (Lit1.getClass() == Lit2.getClass() && dynamic_cast<const LitteralNumerique&>(Lit1).getValue() >= dynamic_cast<const LitteralNumerique&>(Lit2).getValue())
		return true;
	return(res);
}

bool operator <= (const Litteral& Lit1, const Litteral& Lit2)
{
	bool res = false;
	if (Lit1.getClass() == Lit2.getClass() && dynamic_cast<const LitteralNumerique&>(Lit1).getValue() <= dynamic_cast<const LitteralNumerique&>(Lit2).getValue())
		return true;
	return(res);
}

bool operator < (const Litteral& Lit1, const Litteral& Lit2)
{
	bool res = false;
	if (Lit1.getClass() == Lit2.getClass() && dynamic_cast<const LitteralNumerique&>(Lit1).getValue() < dynamic_cast<const LitteralNumerique&>(Lit2).getValue())
		return true;
	return(res);
}

bool operator > (const Litteral& Lit1, const Litteral& Lit2)
{
	bool res = false;
	if (Lit1.getClass() == Lit2.getClass() && dynamic_cast<const LitteralNumerique&>(Lit1).getValue() > dynamic_cast<const LitteralNumerique&>(Lit2).getValue())
		return true;
	return(res);
}
