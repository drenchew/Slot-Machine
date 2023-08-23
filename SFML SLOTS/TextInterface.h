#pragma once

#ifndef TEXT_INTERFACE_H
#define TEXT_INTERFACE_H

#include <SFML/Graphics.hpp>

class TextInterface
{
public:

	TextInterface(const sf::Vector2f& position, const sf::Vector2f& size)
	{
		_font.loadFromFile(".\\assets\\fonts\\BAUHS93.TTF");

		_text.setFont(_font);
		_text.setCharacterSize(20);
		_text.setFillColor(sf::Color::Black);
		_text.setPosition(position + sf::Vector2f(30, 10));
	}

	virtual ~TextInterface() = default;

	 virtual void draw(sf::RenderWindow& window) = 0;


protected:
	sf::Text _text;
	sf::Font _font;
};

#endif // !TEXT_INTERFACE_H