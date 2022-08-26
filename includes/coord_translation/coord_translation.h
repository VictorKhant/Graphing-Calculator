#ifndef COORD_H
#define COORD_H
#include "../graph_info/graph_info.h"
class Coord_trans
{
public:
    Coord_trans(Graph_info *_info);
    sf::Vector2f translate(sf::Vector2f point);
    sf::Vector2f operator()(sf::Vector2f point);

private:
    Graph_info *g;
};
#endif