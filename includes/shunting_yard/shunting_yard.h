#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include <iostream>
#include <iomanip>
using namespace std;
#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/token.h"
#include "../token/integer.h"
#include "../token/operator.h"
#include "../token/function.h"
#include "../token/leftparen.h"
#include "../token/rightparen.h"
class ShuntingYard
{
public:
    ShuntingYard();
    ShuntingYard(const Queue<Token *> &other);
    void infix(const Queue<Token *> &other);
    Queue<Token *> postfix();
    Queue<Token *> postfix(const Queue<Token *> &other);

private:
    Queue<Token *> _input;
};
#endif