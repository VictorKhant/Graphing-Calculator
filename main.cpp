#include <iostream>
#include <iomanip>
#include <cmath>

#include <set>
#include <vector>
using namespace std;
//------------------------------------------------------------------------------------------
// Files we are testing:

#include "includes/animate/animate.h"
#include "includes/token/tokenizer.h"
using namespace std;

int main(int argv, char **argc)
{
    cout << "\n\n"
         << endl;
    animate game;
    game.run();
    // Tokenizer T("sin(x)");
    // Queue<Token *> infix;
    // infix = T.to_infix();
    // infix.print_pointers();
    cout << "\n\n\n=====================" << endl;
    return 0;
}
