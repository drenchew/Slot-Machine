#pragma once

#ifndef BASE_TEXT_H
#define BASE_TEXT_H

#include <SFML/Graphics.hpp>

class BaseText
{
public:

	BaseText(const sf::Vector2f& position, const sf::Vector2f& size)
	{
		_font.loadFromFile(".\\assets\\fonts\\BAUHS93.TTF");

		_text.setFont(_font);
		_text.setCharacterSize(20);
		_text.setFillColor(sf::Color::Black);
		_text.setPosition(position + sf::Vector2f(30, 10));
	}

	void change_size(const size_t& val)
	{
		_text.setCharacterSize(val);
	}

	void set_position(const sf::Vector2f& position)
	{
		_text.setPosition(position);
	}

	 virtual ~BaseText() = default;

	 virtual void draw(sf::RenderWindow& window)
	 {
		 window.draw(_text);
	 }


	 virtual void set_text(const std::string& input)
	 {
		 this->_text.setString(input);
	 }
		 


protected:
	sf::Text _text;
	sf::Font _font;
};

#endif // !BASE_TEXT_H