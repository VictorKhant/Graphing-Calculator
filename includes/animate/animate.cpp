#include "animate.h"
#include "../constants_screen/constants_screen.h"
#include <iostream>

using namespace std;
#include "../system/system.h"

animate::animate() : sidebar(WORK_PANEL, SIDE_BAR)
{

    _info = new Graph_info("x*sin(1/x)", sf::Vector2f(WORK_PANEL, SCREEN_HEIGHT), sf::Vector2f(450, 450), sf::Vector2f(100, 100), sf::Vector2f(-5, 5), 10000);
    system = System(_info);
    is_clicked = 0;
    background.setSize(sf::Vector2f(900, 900));
    background.setFillColor(sf::Color(49.44, 49.47, 49.43));
    background.setPosition(sf::Vector2f(0, 0));
    cout << "animate CTOR: TOP" << endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Final Project");
    // VideoMode class has functions to detect screen size etc.
    // RenderWindow constructor has a third argumnet to set style
    // of the window: resize, fullscreen etc.

    // System will be implemented to manage a vector of objects to be animated.
    //   at that point, the constructor of the System class will take a vector
    //   of objects created by the animate object.
    //   animate will
    // system = System();
    window.setFramerateLimit(60);

    mouseIn = true;

    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout << "Geme CTOR. preparing to load the font." << endl;
    //--- FONT ----------
    // font file must be in the "working directory:
    //      debug folder
    // Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    // font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("../../arial.ttf"))
    {
        cout << "animate() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }
    input_box.setFont(font); // For the user input
    input_box.setCharacterSize(20);
    input_box.setStyle(sf::Text::Bold);
    input_box.setStyle(sf::Text::Underlined);
    input_box.setFillColor(sf::Color(98, 52, 18));
    input_box.setPosition(sf::Vector2f(10.f, 10.f));

    text_back.setSize(sf::Vector2f(200, 30)); // For the background of input_box
    text_back.setFillColor(sf::Color::White);
    text_back.setPosition(sf::Vector2f(10, 10));

    myTextLabel = sf::Text("Graphing Calculator", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setFillColor(sf::Color(98, 52, 18));
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT - myTextLabel.getLocalBounds().height - 5));

    string line; // temp string to push into history array
    // string filename("../history.txt");
    outs.open("../../includes/animate/history.txt", ios::app); // To save datas from input
    if (!outs.is_open())
    {
        cout << "output file opening failed.\n";
    }

    in.open("../../includes/animate/history.txt"); // To use the saved dates
    if (!in.is_open())
    {
        cout << "input file opening failed.\n";
    }

    while (getline(in, line))
    {
        history.push_back(line);
    }
    text_box = false; // close text_box initially
    screen_domain = sf::Vector2f(-16.00, 16.00);

    box_height = 320;
    for (int i = 0; i < history.size(); i++)
    {
        boxes.push_back(Sidebar::Rect(history[i], sf::Vector2f(WORK_PANEL, box_height), font));
        box_height += 35;
    }
    mode1 = Sidebar::Rect("LIGHT", sf::Vector2f(WORK_PANEL - 50, 700), font);
    mode2 = Sidebar::Rect("DARK", sf::Vector2f(WORK_PANEL + 50, 700), font);
    mode2.set_color(sf::Color::White);
    polar = Sidebar::Rect("POLAR", sf::Vector2f(WORK_PANEL - 50, 750), font);
    rectangular = Sidebar::Rect("Rectangular", sf::Vector2f(WORK_PANEL + 50, 750), font);
    rectangular.set_color(sf::Color::White);
    cout << "animate instantiated successfully." << endl;
}

void animate::Draw()
{
    // Look at the data and based on the data, draw shapes on window object.
    window.draw(background);
    system.Draw(window);

    if (mouseIn)
    {
        window.draw(mousePoint);
    }

    sidebar.draw(window);
    for (int i = 0; i < boxes.size(); i++)
    {
        boxes[i].Draw_boxes(window);
    }
    // cout << "here";
    //- - - - - - - - - - - - - - - - - - -
    // getPosition() gives you screen coords, getPosition(window) gives you window coords
    // cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    // drawing Test: . . . . . . . . . . . .
    // This is how you draw text:)
    if (text_box)
    {
        window.draw(text_back);
    }
    window.draw(myTextLabel);
    window.draw(input_box);
    mode1.Draw_boxes(window);
    mode2.Draw_boxes(window);
    polar.Draw_boxes(window);
    rectangular.Draw_boxes(window);
    //. . . . . . . . . . . . . . . . . . .
}

void animate::update()
{
    // cause changes to the data for the next frame
    system.Step(command);
    command = 0;
    if (mouseIn)
    {
        // mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x - 5,
                               sf::Mouse::getPosition(window).y - 5);

        // mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);
        sidebar[SB_DOMAIN] = "Domain: (" + to_string(_info->domain.x) + "\n, " + to_string(_info->domain.y) + ")";
        sidebar[SB_HISTORY - 1] = "Press S to save \nto history";
        // for (int i = 0; i < history.size(); i++) // To show the saved histories
        // {
        //     sidebar[SB_HISTORY + i] = history[i];
        // }
        if (text_box) // To show status of text box
        {
            sidebar[SB_TEXT_BOX] = "Text Box is opened\n(Click Enter to close)";
        }
        else
        {
            sidebar[SB_TEXT_BOX] = "Text Box is closed\n(Click Enter to open)";
        }
        sidebar[SB_RESET_BUTTOM] = "Press Space to reset \nto origin"; // Reset the view
    }
}
void animate::render()
{
    window.clear();
    Draw();
    window.display();
}

void animate::processEvents()
{
    sf::Event event;
    float mouseX, mouseY;
    string str;
    while (window.pollEvent(event)) // or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;

        // key pressed
        case sf::Event::KeyPressed:
            switch (event.key.code) // Arrow keys to move graph and press R to reset
            {
            case sf::Keyboard::Left:
                sidebar[SB_KEY_PRESSED] = "MOVE LEFT";
                _info->domain.x -= 3 / (900 / (_info->domain.y - _info->domain.x));
                _info->domain.y -= 3 / (900 / (_info->domain.y - _info->domain.x));
                // _info->origin.x += 900 / (_info->domain.y - _info->domain.x);
                _info->origin.x += 3;
                command = 4;
                break;
            case sf::Keyboard::Right:
                sidebar[SB_KEY_PRESSED] = "MOVE RIGHT";
                command = 6;
                _info->domain.x += 3 / (900 / (_info->domain.y - _info->domain.x));
                _info->domain.y += 3 / (900 / (_info->domain.y - _info->domain.x));
                //_info->origin.x -= 900 / (_info->domain.y - _info->domain.x);
                _info->origin.x -= 3;
                break;
            case sf::Keyboard::Up:
                sidebar[SB_KEY_PRESSED] = "MOVE UP";
                _info->origin.y += 10;
                break;
            case sf::Keyboard::Down:
                sidebar[SB_KEY_PRESSED] = "MOVE DOWN";
                _info->origin.y -= 10;
                break;
            case sf::Keyboard::Escape:
                sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                in.close();
                outs.close();
                window.close();
                delete _info;
                break;
            case sf::Keyboard::Space:
                if (!text_box)
                {
                    _info->origin = sf::Vector2f(450, 450);
                    _info->domain = sf::Vector2f(-10, 10);
                    _info->scale.x = 900 / (_info->domain.y - _info->domain.x);
                    _info->scale.y = 900 / (_info->domain.y - _info->domain.x);
                    break;
                }
                else
                    break;
            case sf::Keyboard::Enter: // Enter to change the graph as input
                if (text_box)
                {
                    str = input_box.getString();
                    if (!str.empty())
                    {
                        _info->equation = str;
                    }
                    text_box = false;
                    boxes[is_clicked].set_color(sf::Color(169, 169, 169));
                }
                else
                {
                    text_box = true;
                }
                str.erase();
                input_box.setString(str);
                break;
            case sf::Keyboard::Num1: // Press 1 to graph History 1
                if ((history.size() >= 1) && (!text_box))
                {
                    _info->equation = history[0];
                }
                break;
            case sf::Keyboard::Num2: // Press 2 to graph History 2
                if ((history.size() >= 2) && (!text_box))
                {
                    _info->equation = history[1];
                }
                break;
            case sf::Keyboard::Num3: // Press 3 to graph History 3
                if ((history.size() >= 3) && (!text_box))
                {
                    _info->equation = history[2];
                }
                break;
            case sf::Keyboard::Num4: // Press 4 to graph History 4
                if ((history.size() >= 4) && (!text_box))
                {
                    _info->equation = history[3];
                }
                break;
            case sf::Keyboard::Num5: // Press 5 to graph History 5
                if ((history.size() >= 5) && (!text_box))
                {
                    _info->equation = history[4];
                }
                break;
            case sf::Keyboard::Num6: // Press 6 to graph History 6
                if ((history.size() >= 6) && (!text_box))
                {
                    _info->equation = history[5];
                }
                break;
            case sf::Keyboard::Num7: // Press 7 to graph History 7
                if ((history.size() >= 7) && (!text_box))
                {
                    _info->equation = history[6];
                }
                break;
            case sf::Keyboard::Num8: // Press 8 to graph History 8
                if ((history.size() >= 8) && (!text_box))
                {
                    _info->equation = history[7];
                }
                break;
            case sf::Keyboard::Num9: // Press 9 to graph History 9
                if ((history.size() >= 9) && (!text_box))
                {
                    _info->equation = history[8];
                }
                break;
            case sf::Keyboard::Num0: // Press 0 to graph History 10
                if ((history.size() >= 10) && (!text_box))
                {
                    _info->equation = history[9];
                }
                break;
            case sf::Keyboard::S: // Press S to save to history
                if ((!(_info->equation.empty())) && (history.size() != 10) && (!text_box))
                {
                    history.push_back(_info->equation);
                    outs << _info->equation << endl;
                    boxes.push_back(Sidebar::Rect(history[history.size() - 1], sf::Vector2f(WORK_PANEL, box_height), font));
                    box_height += 27;
                }
                break;
            }

            break;
        case sf::Event::MouseWheelScrolled:
            if (event.mouseWheelScroll.delta > 0)
            {
                // _info->scale.x += 5;
                // _info->scale.y += 5;
                _info->domain.x /= 1.5;
                _info->domain.y /= 1.5;
                _info->scale.x = 900 / (_info->domain.y - _info->domain.x);
                _info->scale.y = 900 / (_info->domain.y - _info->domain.x);
                sidebar[SB_MOUSE_WHEEL_SCROLLED] = "ZOOMING IN";
            }
            else if (event.mouseWheelScroll.delta < 0)
            {
                // _info->scale.x -= 5;
                // _info->scale.y -= 5;
                _info->domain.x *= 1.5;
                _info->domain.y *= 1.5;
                _info->scale.x = 900 / (_info->domain.y - _info->domain.x);
                _info->scale.y = 900 / (_info->domain.y - _info->domain.x);
                sidebar[SB_MOUSE_WHEEL_SCROLLED] = "ZOOMING OUT";
            }
            break;

        case sf::Event::MouseEntered:
            mouseIn = true;
            break;

        case sf::Event::MouseLeft:
            mouseIn = false;
            break;

        case sf::Event::MouseMoved:
            mouseX = event.mouseMove.x;
            mouseY = event.mouseMove.y;
            // Do something with it if you need to...
            break;
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                                            mouse_pos_string(window);
                sf::Vector2f mpos = (sf::Vector2f)sf::Mouse::getPosition(window);
                ;
                for (int i = 0; i < history.size(); i++)
                {

                    if (boxes[i].get_rectangle().getGlobalBounds().contains(mpos))
                    {
                        boxes[is_clicked].set_color(sf::Color(169, 169, 169));
                        boxes[i].set_color(sf::Color::White);
                        _info->equation = history[i];
                        is_clicked = i;

                        break;
                    }
                }
                if (mode1.get_rectangle().getGlobalBounds().contains(mpos))
                {
                    mode1.set_color(sf::Color::White);
                    mode2.set_color(sf::Color(169, 169, 169));
                    background.setFillColor(sf::Color(191, 191, 191));
                    _info->color = sf::Color::Black;
                    _info->graph_color = sf::Color::Red;
                }
                else if (mode2.get_rectangle().getGlobalBounds().contains(mpos))
                {
                    mode2.set_color(sf::Color::White);
                    mode1.set_color(sf::Color(169, 169, 169));
                    background.setFillColor(sf::Color(49.44, 49.47, 49.43));
                    _info->color = sf::Color::White;
                    _info->graph_color = sf::Color(255, 215, 0);
                }
                else if (polar.get_rectangle().getGlobalBounds().contains(mpos))
                {
                    _info->is_polar = true;
                    polar.set_color(sf::Color::White);
                    rectangular.set_color(sf::Color(169, 169, 169));
                }
                else if (rectangular.get_rectangle().getGlobalBounds().contains(mpos))
                {
                    _info->is_polar = false;
                    rectangular.set_color(sf::Color::White);
                    polar.set_color(sf::Color(169, 169, 169));
                }
                break;
            }
            else
            {
                sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                                            mouse_pos_string(window);
            }
            break;
        case sf::Event::TextEntered:
            if (text_box)
            {
                str = input_box.getString();
                if ((event.text.unicode > 31) && (event.text.unicode < 128))
                {
                    str.push_back(static_cast<char>(event.text.unicode));
                    // str = input_box.getString() + static_cast<char>(event.text.unicode);
                    input_box.setString(str);
                }
                else if (event.text.unicode = 8)
                {
                    if (!str.empty())
                        str.erase(str.size() - 1, 1);
                    input_box.setString(str);
                }
            }
            break;
        default:
            break;
        }
    }
}
void animate::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render(); // clear/draw/display
    }
    cout << endl
         << "-------ANIMATE MAIN LOOP EXITING ------------" << endl;
}

string mouse_pos_string(sf::RenderWindow &window)
{
    return "(" +
           to_string(sf::Mouse::getPosition(window).x) +
           ", " +
           to_string(sf::Mouse::getPosition(window).y) +
           ")";
}
