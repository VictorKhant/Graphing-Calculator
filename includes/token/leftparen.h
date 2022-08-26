#ifndef LEFTPAREN_H
#define LEFTPAREN_H
#include <iostream>
#include <iomanip>
#include "token.h"
using namespace std;

class LeftParen : public Token
{
public:
    LeftParen();
    void Print(ostream &outs = cout) const;
    TOKEN_TYPES TypeOf() { return LPAREN; }

private:
    char i;
};
#endif