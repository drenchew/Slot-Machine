#include "Row.h"

Row::Row(const float x, const float y) : bell(BELL), seven(SEVEN), cherry(CHERRY), watermelon(WATERMELON), _x(x), _y(y)
{
    populate();
}

std::vector<Symbol>& Row::get_row()
{
    return _row;
}

void Row::populate()
{
    if (!_row.empty())
    {
        _row.clear();
    }

    for (int i = 0; i < 5; ++i)
    {
        SymbolType generated_symbol = static_cast<SymbolType>(rand() % 4);

        switch (generated_symbol)
        {
        case BELL: _row.push_back(bell); break;
        case SEVEN: _row.push_back(seven); break;
        case WATERMELON: _row.push_back(watermelon); break;
        case CHERRY: _row.push_back(cherry); break;
        }
    }

    float temp_x = _x;
    for (auto& row : _row)
    {
        row.set_position(temp_x, _y);
        temp_x += 100;
    }
}
