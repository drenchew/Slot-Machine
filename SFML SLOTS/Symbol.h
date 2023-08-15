#pragma once

#include <SFML/Graphics.hpp>
#include"Defines.h"



class Symbol
{
public:
    Symbol();
    Symbol(SymbolType type);

    const SymbolType get_type() const;
    sf::Sprite& get_sprite();
    void set_position(float w, float h);
    void move_position(float w, float h);
    void scale(float a, float b);

private:
    sf::Texture _symbolTexture;
    sf::Sprite _symbolSprite;
    SymbolType _type;
};
