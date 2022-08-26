#include "integer.h"

Integer::Integer() : i(0)
{
}

Integer::Integer(double value) : i(value)
{
}

Integer::Integer(string value)
{
    i = stod(value.c_str());
}

void Integer::Print(ostream &outs) const
{
    outs << "[" << i << "]";
}