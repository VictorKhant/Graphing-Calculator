#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "../queue/MyQueue.h"
#include "token.h"
#include "function.h"
#include "integer.h"
#include "operator.h"
#include "leftparen.h"
#include "rightparen.h"
using namespace std;
class Tokenizer
{
public:
    Tokenizer();
    Tokenizer(string equation);
    Queue<Token *> to_infix();
    void delete_memory();

private:
    string _eq;
    Queue<Token *> queue;
};
#endif