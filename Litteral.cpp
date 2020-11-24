#include "Litteral.h"


bool operator == (const Litteral& Lit1, const Litteral& Lit2)
{
	if (Lit1.getClass() == Lit2.getClass() || ((Lit1.getClass() != EXPLIT && Lit2.getClass() != EXPLIT) && (Lit1.getClass() != PROGLIT && Lit2.getClass() != PROGLIT)))
		return (dynamic_cast<const LitteralNumerique&>(Lit1).getValue() == dynamic_cast<const LitteralNumerique&>(Lit2).getValue());
	return false;
}

bool operator != (const Litteral& Lit1, const Litteral& Lit2)
{
	if (Lit1.getClass() == Lit2.getClass() || ((Lit1.getClass() != EXPLIT && Lit2.getClass() != EXPLIT) && (Lit1.getClass() != PROGLIT && Lit2.getClass() != PROGLIT)))
		return (dynamic_cast<const LitteralNumerique&>(Lit1).getValue() != dynamic_cast<const LitteralNumerique&>(Lit2).getValue());
	return false;
}

bool operator >= (const Litteral& Lit1, const Litteral& Lit2)
{
	if (Lit1.getClass() == Lit2.getClass() || ((Lit1.getClass() != EXPLIT && Lit2.getClass() != EXPLIT) && (Lit1.getClass() != PROGLIT && Lit2.getClass() != PROGLIT)))
		return (dynamic_cast<const LitteralNumerique&>(Lit1).getValue() >= dynamic_cast<const LitteralNumerique&>(Lit2).getValue());
	return false;
}

bool operator <= (const Litteral& Lit1, const Litteral& Lit2)
{
	if (Lit1.getClass() == Lit2.getClass() || ((Lit1.getClass() != EXPLIT && Lit2.getClass() != EXPLIT) && (Lit1.getClass() != PROGLIT && Lit2.getClass() != PROGLIT)))
		return (dynamic_cast<const LitteralNumerique&>(Lit1).getValue() <= dynamic_cast<const LitteralNumerique&>(Lit2).getValue());
	return false;
}

bool operator < (const Litteral& Lit1, const Litteral& Lit2)
{
	if (Lit1.getClass() == Lit2.getClass() || ((Lit1.getClass() != EXPLIT && Lit2.getClass() != EXPLIT) && (Lit1.getClass() != PROGLIT && Lit2.getClass() != PROGLIT)))
		return (dynamic_cast<const LitteralNumerique&>(Lit1).getValue() < dynamic_cast<const LitteralNumerique&>(Lit2).getValue());
	return false;
}

bool operator > (const Litteral& Lit1, const Litteral& Lit2)
{
	if (Lit1.getClass() == Lit2.getClass() || ((Lit1.getClass() != EXPLIT && Lit2.getClass() != EXPLIT) && (Lit1.getClass() != PROGLIT && Lit2.getClass() != PROGLIT)))
		return (dynamic_cast<const LitteralNumerique&>(Lit1).getValue() > dynamic_cast<const LitteralNumerique&>(Lit2).getValue());
	return false;
}
