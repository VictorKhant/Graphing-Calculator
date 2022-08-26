#include "graph_info.h"

Graph_info::Graph_info(string eq, sf::Vector2f window_di, sf::Vector2f ori, sf::Vector2f scal, sf::Vector2f dom, int pois)
{
    equation = eq;
    window_dimensions = window_di; // sf::Vector2f(600, 600);
    origin = ori;                  // sf::Vector2f(300, 300);
    scale = scal;
    domain = dom;  // sf::Vector2f(-5, 5);
    points = pois; // 11;
    color = sf::Color::White;
    graph_color = sf::Color(255, 215, 0);
    is_polar = false;
}