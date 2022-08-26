#ifndef GRAPH_H
#define GRAPH_H
#include "../plot/plot.h"
class Graph
{
public:
    Graph();
    Graph(Graph_info *info);
    void set_info();
    void update(Graph_info *info);
    void draw(sf::RenderWindow &window);

private:
    Graph_info *_info;
    Plot _plotter;
    vector<sf::Vector2f> _points;
};
#endif