#include "leftparen.h"

LeftParen::LeftParen() : i('(')
{
}
void LeftParen::Print(ostream &outs) const
{
    outs << "[" << i << "]";
}