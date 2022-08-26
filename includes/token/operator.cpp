#include "operator.h"
#include <cmath>
Operator::Operator()
{
}

Operator::Operator(char value) : i(value)
{
}
Operator::Operator(string value)
{
    i = value[0];
}

void Operator::Print(ostream &outs) const
{
    outs << "[" << i << "]";
}

// TOKEN_TYPES Operator::S_Type()
// {
//     if (i == '+' || i == '-')
//     {
//         return PLUS_MINUS;
//     }
//     if (i == '*' || i == '/')
//     {
//         return MUL_DIV;
//     }
//     if (i == '^')
//     {
//         return POWER;
//     }
//     return FUNCTION;
// }

double Operator::evaluate(double value1, double value2)
{
    if (i == '+')
    {
        return (value1 + value2);
    }
    if (i == '-')
    {
        return (value2 - value1);
    }
    if (i == '*')
    {
        return (value1 * value2);
    }
    if (i == '/')
    {
        return (value2 / value1);
    }
    if (i == '^')
    {
        return pow(value2, value1);
    }
}

int Operator::precedence()
{
    if (i == '+' || i == '-')
    {
        return 1;
    }
    if (i == '*' || i == '/')
    {
        return 2;
    }
    if (i == '^')
    {
        return 3;
    }
}