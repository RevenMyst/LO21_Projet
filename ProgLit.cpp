#include "ProgLit.h"

std::string ProgLit::toString(int size) const
{
    std::string str = "[ ";
    for (Operand o : operands) {
        str = str + o.toString(size) + " ";
    }
    str += "]";
    return str;
}
