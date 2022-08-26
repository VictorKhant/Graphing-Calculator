#include "graph.h"

Graph::Graph()
{
    _info = nullptr;
}
Graph::Graph(Graph_info *info) : _plotter(Plot(info))
{
    // cout << "here in Graph ctor";
    _info = info;
    set_info();
}

void Graph::set_info()
{
    // cout << "here in set_info";
    _plotter = Plot(_info);

    _points = _plotter();
    // cout << "here in set_info after getting points";
}

void Graph::update(Graph_info *info)
{
    _info = info;
    set_info();
}
void Graph::draw(sf::RenderWindow &window)
{
    // sf::RectangleShape x;
    // sf::RectangleShape y;
    // x.setSize(sf::Vector2f(0, 900));
    // x.setPosition(sf::Vector2f(450, 0));
    // y.setSize(sf::Vector2f(900, 0));
    // y.setPosition(sf::Vector2f(0, 450));
    // x.setFillColor(_info->color);
    // y.setFillColor(_info->color);
    sf::Vertex x_axis[2];
    x_axis[0].color = _info->color;
    x_axis[1].color = _info->color;
    x_axis[0].position = sf::Vector2f(0, _info->origin.y);
    x_axis[1].position = sf::Vector2f(_info->window_dimensions.x, _info->origin.y);
    sf::Vertex y_axis[2];
    y_axis[0].color = _info->color;
    y_axis[1].color = _info->color;
    y_axis[0].position = sf::Vector2f(_info->origin.x, 0);
    y_axis[1].position = sf::Vector2f(_info->origin.x, _info->window_dimensions.y);
    window.draw(x_axis, 2, sf::Lines);
    window.draw(y_axis, 2, sf::Lines);
    // window.draw(x);
    // window.draw(y);
    for (int i = 0; i < _points.size(); i++)
    {
        // cout << "here";
        // cout << _points[i].y;
        sf::Vertex point(_points[i], _info->graph_color);
        window.draw(&point, 1, sf::Points);
        // sf::CircleShape c(1);
        // c.setPosition(_points[i]);
        // c.setFillColor(sf::Color::Green);
        // window.draw(c);
    }
}