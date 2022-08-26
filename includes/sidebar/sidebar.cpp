#include "sidebar.h"
#include "../constants_screen/constants_screen.h"
Sidebar::Sidebar()
{
}

Sidebar::Sidebar(float left, float width) : _left(left), _width(width)
{
    cout << "Sidebar CTOR: TOP" << endl;
    items.reserve(50);

    // set up the sidebar rectangle:
    rect.setFillColor(sf::Color(169, 169, 169)); //(192,192,192)); //silver
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));

    // box.setPosition(sf::Vector2f(left, 320));
    // box.setFillColor(sf::Color::Green);
    // box.setSize(sf::Vector2f(width / 2, 25));

    cout << "Sidebar CTOR: about to load font." << endl;

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // the font file must be in the "working directory"
    //  check projects->run->working directory
    //       [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("../../Roboto-Thin.ttf"))
    {
        cout << "Sidebar() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout << "Sidebar CTOR: loaded font." << endl;

    //. . . . . text / font problems: . . . . . . . .
    // initializing text object in this way caused problems
    // (hangs!)
    // only when sb_text was a private member and worked fine
    // when it was a public member. Probably not releavant,
    // but still strange!
    //
    // sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout << "Sidebar CTOR: Text object initialized." << endl;
    sb_text.setFont(font);
    sb_text.setCharacterSize(20);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setFillColor(sf::Color(98, 52, 18));

    ////this is how you would position text on screen:
    // sb_text.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-sb_text.getLocalBounds().height-5));

    items.push_back("sidebar sample text");
    // Fill the items vector with empty strings so that we can use [] to read them:
    for (int i = 0; i < 30; i++)
    {
        items.push_back("");
    }

    // Buttom rectangles

    cout << "Sidebar: CTOR: Exit." << endl;
}

void Sidebar::draw(sf::RenderWindow &window)
{
    const double VERTICAL_LINE_SPACING = 5.0;
    const double LEFT_MARGIN = 10.0;

    window.draw(rect);
    // for (int i = 9; i < items.size(); i++)
    // {
    //     cout << "here";
    //     boxes[0].Draw_boxes(window);
    // }
    float height = 10;

    for (vector<string>::iterator it = items.begin();
         it != items.end(); it++)
    {
        bool blank = false;
        if (it->length() == 0)
        {
            // empty rows must be taken into account (getLocalBounds())
            //     but not drawn
            blank = true;
            sb_text.setString("BLANK");
        }
        else
        {
            sb_text.setString(it->c_str());
        }
        sb_text.setPosition(sf::Vector2f(_left + LEFT_MARGIN, height));
        height += sb_text.getLocalBounds().height + VERTICAL_LINE_SPACING;
        // cout << sb_text.getPosition().y << endl;
        if (!blank)
            window.draw(sb_text);
    }
    // cout << items.size() << endl;
    // Rect r(items[9],sf::Vector2f() );
    // boxes.push_back(r);
    // cout << items[9];
}

string &Sidebar::operator[](int index)
{
    return items[index];
}

Sidebar::Rect::Rect(string str, sf::Vector2f pos, sf::Font &font)
{
    // font.loadFromFile("../Roboto-Thin.ttf");
    equation.setFont(font);
    equation.setCharacterSize(20);
    equation.setString(str);
    equation.setPosition(sf::Vector2f(pos.x + 60, pos.y));
    // equation.setOrigin(sf::Vector2f(x, pos.y));
    equation.setFillColor(sf::Color(98, 52, 18));
    string s1;
    r.setPosition(sf::Vector2f(pos.x + 55, pos.y + 2.5));
    r.setFillColor(sf::Color(169, 169, 169));
    r.setOutlineThickness(1.f);
    r.setOutlineColor(sf::Color::Black);
    r.setSize(sf::Vector2f(SIDE_BAR / 2, 25));
    //     sf::Vector2f txtSize(equation.getLocalBounds().width, equation.getLocalBounds().height);
    //     sf::Vector2f containerSize(r.getGlobalBounds().width, r.getGlobalBounds().height);
    //     equation.setPosition((containerSize / 2.f) - (txtSize / 2.f));
}
void Sidebar::Rect::Draw_boxes(sf::RenderWindow &window)
{
    window.draw(r);
    window.draw(equation);
    //
    // cout << "here";
}
sf::RectangleShape Sidebar::Rect::get_rectangle() const
{
    return r;
}

void Sidebar::Rect::set_color(sf::Color color)
{
    r.setFillColor(color);
}