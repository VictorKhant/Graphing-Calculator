#include "plot.h"
#include <cmath>
Plot::Plot()
{
    _info = nullptr;
}
Plot::Plot(Graph_info *info)
{
    _info = info;
    set_info();
}

void Plot::set_info()
{
    T = Tokenizer(_info->equation);
    ShuntingYard sy(T.to_infix());
    postfix = sy.postfix();
    // postfix.print_pointers();
}

vector<sf::Vector2f> Plot::operator()()
{

    vector<sf::Vector2f> result;
    Coord_trans transform(_info);
    sf::Vector2f point;
    double temp = (_info->domain.y - _info->domain.x) / _info->points;
    for (double i = _info->domain.x; i <= _info->domain.y; i += temp)
    {
        RPN rpn(postfix);
        point = sf::Vector2f(i, rpn(i));
        result.push_back(transform(point));
    }
    T.delete_memory();
    return result;
}