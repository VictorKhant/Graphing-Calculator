#include "tokenizer.h"
Tokenizer::Tokenizer()
{
}
Tokenizer::Tokenizer(string equation)
{
    _eq = equation;
}

Queue<Token *> Tokenizer::to_infix()
{
    Queue<Token *> infix;
    Token *push;
    while (!_eq.empty())
        // cout << _eq[0];
        switch (_eq[0])
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            push = new Operator(_eq[0]);
            infix.push(push);
            queue.push(push);
            _eq.erase(0, 1);
            break;
        case 'x':
        case 'X':
            push = new Function("X");
            infix.push(push);
            queue.push(push);
            _eq.erase(0, 1);
            break;
        case 's':
            if (_eq[1] == 'i' && _eq[2] == 'n')
            {
                push = new Function("sin");
                infix.push(push);
                queue.push(push);
                _eq.erase(0, 3);
            }
            break;
        case 'c':
            if (_eq[1] == 'o' && _eq[2] == 's')
            {
                push = new Function("cos");
                infix.push(push);
                queue.push(push);
                _eq.erase(0, 3);
            }
            break;
        case 't':
            if (_eq[1] == 'a' && _eq[2] == 'n')
            {
                push = new Function("tan");
                infix.push(push);
                queue.push(push);
                _eq.erase(0, 3);
            }
            break;
        case 'm':
            if (_eq[1] == 'a' && _eq[2] == 'x')
            {
                push = new Function("max");
                infix.push(push);
                queue.push(push);
                _eq.erase(0, 3);
            }
            else if (_eq[1] == 'i' && _eq[2] == 'n')
            {
                push = new Function("min");
                infix.push(push);
                queue.push(push);
                _eq.erase(0, 3);
            }
            break;
        case '(':
            push = new LeftParen();
            infix.push(push);
            _eq.erase(0, 1);
            break;
        case ')':
            push = new RightParen();
            infix.push(push);
            _eq.erase(0, 1);
            break;
        default:

            if (isdigit(_eq[0]))
            {
                string str;
                while (isdigit(_eq[0]))
                {
                    str += _eq[0];
                    _eq.erase(0, 1);
                }
                push = new Integer(str);
                infix.push(push);
            }
            else
                _eq.erase(0, 1);
            break;
        }
    return infix;
}
void Tokenizer::delete_memory()
{
    for (Queue<Token *>::Iterator it = queue.begin(); it != queue.end(); it++)
    {
        delete *it;
    }
}