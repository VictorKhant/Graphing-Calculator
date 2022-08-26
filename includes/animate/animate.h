#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <fstream>
#include "../system/system.h"
#include "../sidebar/sidebar.h"
class animate
{
public:
    animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();

private:
    sf::RenderWindow window;
    System system;   // container for all the animated objects
    Sidebar sidebar; // rectangular message sidebar

    sf::CircleShape mousePoint; // The little red dot
    int command;                // command to send to system
    sf::Font font;              // font to draw on main screen
    sf::Text myTextLabel;       // text to draw on main screen
    sf::Text input_box;         // To input the graph
    bool mouseIn;               // mouse is in the screen
    Graph_info *_info;
    vector<string> history;
    bool text_box; // true if text box is open
    ofstream outs;
    ifstream in;
    sf::RectangleShape text_back; // For text_box's background
    sf::Vector2f screen_domain;
    vector<sf::RectangleShape> click2Load;
    vector<Sidebar::Rect> boxes;
    int box_height;
    int is_clicked;
    sf::RectangleShape background;
    Sidebar::Rect mode1;
    Sidebar::Rect mode2;
    Sidebar::Rect polar;
    Sidebar::Rect rectangular;
};

string mouse_pos_string(sf::RenderWindow &window);

#endif // GAME_H
