#include "shunting_yard.h"

ShuntingYard::ShuntingYard()
{
}
ShuntingYard::ShuntingYard(const Queue<Token *> &other)
{
    _input = other;
}

void ShuntingYard::infix(const Queue<Token *> &other)
{
    _input = other;
}

// Queue<Token *> ShuntingYard::postfix()
// {
//     Stack<Token *> stack;
//     Queue<Token *> result;
//     Token *walker;
//     while (_input.begin() != nullptr)
//     {
//         walker = _input.pop();
//         switch (walker->TypeOf())
//         {
//         case 0:
//             result.push(walker);
//             break;
//         case 1:
//             walker = stack.pop();
//             // _input.print_pointers();
//             // result.print_pointers();
//             // cout << endl;
//             while (walker->TypeOf() != 11)
//             {

//                 result.push(walker);

//                 walker = stack.pop();
//                 // result.print_pointers();
//             }

//             break;
//         case 10:
//             // cout << "Hehe op";
//             if ((stack.begin() == nullptr) || (stack.top()->TypeOf() == 11) || (static_cast<Operator *>(walker)->S_Type() > static_cast<Operator *>(stack.top())->S_Type()))
//             {
//                 // result.print_pointers();
//                 stack.push(walker);
//                 // result.print_pointers();
//             }
//             // else if(stack.top()->TypeOf()==12)
//             // {
//             //     while((stack.begin()!=nullptr)||(stack.top()->TypeOf()==12))
//             // }
//             else
//             {
//                 while ((stack.begin() != nullptr) && (stack.top()->TypeOf() != 11) && (static_cast<Operator *>(walker)->S_Type() <= static_cast<Operator *>(stack.top())->S_Type()))
//                 {
//                     // cout << "before popping:";
//                     // result.print_pointers();
//                     result.push(stack.pop());
//                 }
//                 stack.push(walker);
//             }
//             break;
//         case 11:
//             stack.push(walker);
//             // cout << "here:";
//             break;
//         case 12:
//             // result.print_pointers();
//             // result.push(walker);
//             stack.push(walker);
//             break;
//         default:
//             break;
//         }
//     }
//     while (stack.begin() != nullptr)
//     {
//         result.push(stack.pop());
//     }
//     return result;
// }
Queue<Token *> ShuntingYard::postfix(const Queue<Token *> &other)
{
    _input = other;
    return postfix();
}

Queue<Token *> ShuntingYard::postfix()
{
    Stack<Token *> stack;
    Queue<Token *> result;
    Token *walker;

    while (_input.begin() != nullptr)
    {
        walker = _input.pop();
        switch (walker->TypeOf())
        {
        case 0:
            result.push(walker);
            break;
        case 1:
            while (stack.top()->TypeOf() != 2)
            {
                walker = stack.pop();
                result.push(walker);
            }
            stack.pop();
            break;
        case 2:
            stack.push(walker);
            break;
        case 10:
            if ((stack.empty()) || (stack.top()->TypeOf() == 2) || ((stack.top()->TypeOf() != 11) && (static_cast<Operator *>(stack.top())->precedence() < static_cast<Operator *>(walker)->precedence())))
            {
                stack.push(walker);
            }
            else if (((stack.top()->TypeOf() == 11) || (static_cast<Operator *>(stack.top())->precedence() >= static_cast<Operator *>(walker)->precedence())))
            {
                while ((stack.top()->TypeOf() == 11) || (static_cast<Operator *>(stack.top())->precedence() >= static_cast<Operator *>(walker)->precedence()))
                {
                    result.push(stack.pop());
                    if (stack.empty())
                        break;
                    if (stack.top()->TypeOf() == 2)
                        break;
                }
                stack.push(walker);
            }
            break;
        case 11:
            if ((!stack.empty()) && (stack.top()->TypeOf() == 11))
            {
                result.push(stack.pop());
            }
            stack.push(walker);
            break;
        default:
            break;
        }
    }
    while (stack.begin() != nullptr)
    {
        result.push(stack.pop());
    }
    return result;
}
