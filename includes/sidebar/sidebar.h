#ifndef SIDEBAR_H
#define SIDEBAR_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sidebar
{
public:
    Sidebar();
    Sidebar(float left, float width);
    void draw(sf::RenderWindow &window);
    string &operator[](int index);
    class Rect
    {
    public:
        friend class Sidebar;
        Rect() {}
        Rect(string str, sf::Vector2f pos, sf::Font &font);
        void set_color(sf::Color color);
        sf::RectangleShape get_rectangle() const;
        void Draw_boxes(sf::RenderWindow &window);

    private:
        sf::Text equation;
        sf::Vector2f pos;
        sf::RectangleShape r;
        sf::Font font1;
    };

private:
    sf::RectangleShape rect; // sidebar rectangle
    vector<string> items;    // strings to place on the sidebar
    sf::Font font;           // used to draw text
    sf::Text sb_text;        // used to draw strings on the window object

    float _left;
    float _width;
    // sf::RectangleShape box;
    vector<Rect> boxes;
};

#endif // SIDEBAR_H
