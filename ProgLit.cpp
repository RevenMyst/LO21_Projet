#include "ProgLit.h"

std::string ProgLit::toString() const
{
    std::string str = "[ ";
    for (Operand o : operands) {
        str = str + o.toString() + " ";
    }
    str += "]";
    return str;
}

bool ProgLit::operator==(const Litteral& lit) const
{
    
    return toString() == lit.toString();
    
}
bool ProgLit::operator!=(const Litteral& lit) const
{

    return toString() != lit.toString();

}
