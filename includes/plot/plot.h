#ifndef PLOT_H
#define PLOT_H
#include "../queue/MyQueue.h"
#include "../rpn/rpn.h"
#include "../shunting_yard/shunting_yard.h"
#include "../graph_info/graph_info.h"
#include "../token/tokenizer.h"
#include "../coord_translation/coord_translation.h"
class Plot
{
public:
    Plot();
    Plot(Graph_info *info);
    void set_info();
    vector<sf::Vector2f> operator()();

private:
    Graph_info *_info;
    Queue<Token *> postfix;
    Tokenizer T;
};
#endif