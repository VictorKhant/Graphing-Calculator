#ifndef RPN_H
#define RPN_H
#include <iostream>
#include <iomanip>
using namespace std;
#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/token.h"
#include "../token/integer.h"
#include "../token/operator.h"
#include "../token/function.h"
class RPN
{
public:
    RPN(const Queue<Token *> &other);
    void set_input(const Queue<Token *> &other);
    double evaluate(double value = 0);
    double operator()(double value = 0);

private:
    Queue<Token *> _input;
};

#endif