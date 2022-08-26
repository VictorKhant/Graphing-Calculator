#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H
#include <iostream>
#include <iomanip>
#include "token.h"
using namespace std;

class RightParen : public Token
{
public:
    RightParen();
    void Print(ostream &outs = cout) const;
    TOKEN_TYPES TypeOf() { return RPAREN; }

private:
    char i;
};
#endif