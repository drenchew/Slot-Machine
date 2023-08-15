#pragma once

#include "Symbol.h"
#include <vector>

class Row
{
public:
    const float _x = 0, _y = 0;

    Row(const float x, const float y);
    std::vector<Symbol>& get_row();

   

    void populate();

private:
    Symbol bell, seven, cherry, watermelon;
    std::vector<Symbol> _row;

};
