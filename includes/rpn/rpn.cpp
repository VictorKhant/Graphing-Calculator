#include "rpn.h"
#include <cmath>
const double PI = 22.0 / 7.0;
RPN::RPN(const Queue<Token *> &other)
{
    _input = other;
    // cout << static_cast<Integer *>(_input.front())->IntegerOnly();
}
void RPN::set_input(const Queue<Token *> &other)
{
    _input = other;
}

double RPN::evaluate(double value)
{
    Stack<Token *> stack;
    Queue<Token *> queue;
    Token *walker;
    double value1;
    double value2;
    Token *res;
    string fun;
    // Queue<Token *> input(_input);
    while (_input.begin() != nullptr)
    {
        // cout << static_cast<Integer *>(_input.front())->IntegerOnly() << endl
        //      << endl;
        walker = _input.pop();
        // cout << "popped" << static_cast<Integer *>(walker)->IntegerOnly();
        switch (walker->TypeOf())
        {
        case 0:
            // cout << "pushing" << static_cast<Integer *>(walker)->IntegerOnly() << endl;
            stack.push(walker);
            break;
        case 10:
            value1 = static_cast<Integer *>(stack.pop())->IntegerOnly();
            value2 = static_cast<Integer *>(stack.pop())->IntegerOnly();
            res = new Integer(static_cast<Operator *>(walker)->evaluate(value1, value2));
            stack.push(res);
            queue.push(res);
            break;
        case 11:
            fun = static_cast<Function *>(walker)->FunctionOnly();
            if ((fun == "max") || (fun == "min"))
            {
                value1 = static_cast<Integer *>(stack.pop())->IntegerOnly();
                value2 = static_cast<Integer *>(stack.pop())->IntegerOnly();
                res = new Integer(static_cast<Function *>(walker)->evaluate(value1, value2));
                stack.push(res);
                queue.push(res);
                break;
            }

            else if ((fun == "cos") || (fun == "sin"))
            {
                value = static_cast<Integer *>(stack.pop())->IntegerOnly();
            }
            res = new Integer(static_cast<Function *>(walker)->evaluate(value));
            stack.push(res);
            queue.push(res);
            break;
        default:
            break;
        }
    }
    for (Queue<Token *>::Iterator it = queue.begin(); it != queue.end(); it++)
    {
        delete *it;
    }
    return (static_cast<Integer *>(stack.pop())->IntegerOnly());
}

double RPN::operator()(double value)
{
    return evaluate(value);
}

// Old Operator code
//  cout << "here";
//  cout << static_cast<Operator *>(walker)->CharOnly();
//  if (static_cast<Operator *>(walker)->CharOnly() == '+')
//  {
//      walker = stack.pop();
//      stack.push(new Integer(static_cast<Integer *>(stack.pop())->IntegerOnly() + static_cast<Integer *>(walker)->IntegerOnly()));
//  }
//  if (static_cast<Operator *>(walker)->CharOnly() == '-')
//  {
//      walker = stack.pop();
//      stack.push(new Integer(static_cast<Integer *>(stack.pop())->IntegerOnly() - static_cast<Integer *>(walker)->IntegerOnly()));
//  }
//  if (static_cast<Operator *>(walker)->CharOnly() == '*')
//  {
//      walker = stack.pop();
//      // cout << "char detected";
//      stack.push(new Integer(static_cast<Integer *>(stack.pop())->IntegerOnly() * static_cast<Integer *>(walker)->IntegerOnly()));
//  }
//  if (static_cast<Operator *>(walker)->CharOnly() == '/')
//  {
//      walker = stack.pop();
//      stack.push(new Integer(static_cast<Integer *>(stack.pop())->IntegerOnly() / static_cast<Integer *>(walker)->IntegerOnly()));
//  }
//  if (static_cast<Operator *>(walker)->CharOnly() == '^')
//  {
//      walker = stack.pop();
//      stack.push(new Integer(pow(static_cast<Integer *>(stack.pop())->IntegerOnly(), static_cast<Integer *>(walker)->IntegerOnly())));
//  }
//  walker = stack.pop();

// Old Function code
//  if ((static_cast<Function *>(walker)->FunctionOnly() == "x") || (static_cast<Function *>(walker)->FunctionOnly() == "X"))
//  {
//      stack.push(new Integer(value));
//      break;
//  }
//  if (static_cast<Function *>(walker)->FunctionOnly() == "cos")
//  {
//      stack.push(new Integer(cos(static_cast<Integer *>(stack.pop())->IntegerOnly() * (PI / 180))));
//  }
//  if (static_cast<Function *>(walker)->FunctionOnly() == "sin")
//  {
//      stack.push(new Integer(sin(static_cast<Integer *>(stack.pop())->IntegerOnly() * (PI / 180))));
//  }