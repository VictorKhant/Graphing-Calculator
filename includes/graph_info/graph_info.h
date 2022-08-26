#ifndef GRAPH_INFO
#define GRAPH_INFO
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

struct Graph_info
{
    Graph_info(string eq, sf::Vector2f window_di, sf::Vector2f ori, sf::Vector2f scal, sf::Vector2f dom, int pois);
    string equation;
    sf::Vector2f window_dimensions;
    sf::Vector2f origin;
    sf::Vector2f scale;
    sf::Vector2f domain;
    sf::Color color;
    sf::Color graph_color;
    bool is_polar;
    int points;
};
#endif