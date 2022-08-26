#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <iomanip>
#include "operator.h"
using namespace std;

class Function : public Operator
{
public:
    Function();
    // Function(char value);
    Function(string value);

    void Print(ostream &outs = cout) const;
    TOKEN_TYPES TypeOf() { return FUNCTION; }
    string FunctionOnly() { return i; }
    double evaluate(double value);
    double evaluate(double value1, double value2);

private:
    string i;
};
#endif