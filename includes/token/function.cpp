#include "function.h"
#include <cmath>
#include <string.h>
const double PI = 22.0 / 7.0;
Function::Function()
{
}
Function::Function(string value)
{
    i = value;
}
void Function::Print(ostream &outs) const
{
    outs << "[" << i << "]";
}

double Function::evaluate(double value)
{
    if (i == "x" || i == "X")
    {
        return value;
    }
    if (i == "cos")
    {
        return cos(value);
    }
    if (i == "sin")
    {
        return sin(value);
    }
    if (i == "tan")
    {
        return tan(value);
    }
}
double Function::evaluate(double value1, double value2)
{
    if (i == "max")
    {
        if (value1 > value2)
        {
            return value1;
        }
        return value2;
    }
    if (i == "min")
    {
        if (value1 < value2)
        {
            return value1;
        }
        return value2;
    }
}