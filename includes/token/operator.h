#ifndef OPERATOR_H
#define OPERATOR_H
#include <iostream>
#include <iomanip>
#include "token.h"
using namespace std;

class Operator : public Token
{
public:
    Operator();
    Operator(char value);
    Operator(string value);

    void Print(ostream &outs = cout) const;
    TOKEN_TYPES TypeOf() { return OPERATOR; }
    // TOKEN_TYPES S_Type();
    char CharOnly() { return i; }
    double evaluate(double value1, double value2);
    int precedence();

private:
    char i;
};
#endif