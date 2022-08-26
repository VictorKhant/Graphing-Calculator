#include "rightparen.h"

RightParen::RightParen() : i(')')
{
}
void RightParen::Print(ostream &outs) const
{
    outs << "[" << i << "]";
}