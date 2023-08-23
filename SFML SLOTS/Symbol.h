#pragma once
#ifndef SYMBOL_H
#define SYMBOL_H

#include <SFML/Graphics.hpp>
#include"Defines.h"


class Symbol
{
public:
    Symbol();
    Symbol(SymbolType type);

    const SymbolType get_type() const;
   // sf::Sprite& get_sprite();

    void set_position(float w, float h);
    void move_position(float w, float h);
    void scale(float a, float b);

   const sf::Vector2f get_position() const { return this->_symbolSprite.getPosition(); }

   void draw(sf::RenderWindow& window) const;

private:
    sf::Texture _symbolTexture;
    sf::Sprite _symbolSprite;
    SymbolType _type;
};


#endif // !SYMBOL_H
