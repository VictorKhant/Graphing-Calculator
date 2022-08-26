#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include "constant.h"

using namespace std;

class Token
{
public:
    Token();
    friend ostream &operator<<(ostream &outs, const Token *x);
    friend ostream &operator<<(ostream &outs, const Token &token);
    virtual void Print(ostream &outs = cout) const;
    virtual TOKEN_TYPES TypeOf() {}
};

#endif // TOKEN_H