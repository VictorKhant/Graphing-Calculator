#include "system.h"
#include "../random/random.h"

#include <iostream>

#include "../constants_screen/constants_screen.h"
System::System()
{
    _info = nullptr;
}
System::System(Graph_info *info)
{
    _info = info;
    _g = Graph(_info);
    _info->scale.x = 900 / (_info->domain.y - _info->domain.x);
    _info->scale.y = 900 / (_info->domain.y - _info->domain.x);
}

//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(int command)
{
    _g.update(_info);
}

void System::Draw(sf::RenderWindow &window)
{
    _g.draw(window);
}
