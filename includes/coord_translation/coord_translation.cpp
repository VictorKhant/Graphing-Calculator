#include "coord_translation.h"
#include <cmath>
const double PI = 3.14159;
Coord_trans::Coord_trans(Graph_info *_info)
{
    g = _info;
}
sf::Vector2f Coord_trans::translate(sf::Vector2f point)
{
    if (g->is_polar)
    {
        float theta = point.x;
        float r = point.y;
        point.x = r * cos(theta);
        point.y = r * sin(theta);
    }
    float x = (point.x * g->scale.x + g->origin.x) * (7 / 5);
    float y = -point.y * g->scale.y + g->origin.y;
    return sf::Vector2f(x, y);
}
sf::Vector2f Coord_trans::operator()(sf::Vector2f point)
{
    return translate(point);
}