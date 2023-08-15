#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>

class User
{
public:


	User(){}

	User(const sf::Vector2f& position, const sf::Vector2f& size, double balance) : _balance(balance)
	{
		_font.loadFromFile(".\\BAUHS93.TTF");

		_shape.setSize(size);
		_shape.setFillColor(sf::Color::Transparent);
		_shape.setPosition(position);
		//_shape.setOutlineColor(sf::Color::Blue);
		//_shape.setOutlineThickness(1.0f);

		_text.setFont(_font);

		std::ostringstream ostr;
		ostr << "Your Balance\n";
		ostr << std::fixed << std::setprecision(2) << _balance;
		_text.setString(ostr.str() + "$");

		_text.setCharacterSize(20);
		_text.setFillColor(sf::Color::Black);
		_text.setPosition(position + sf::Vector2f(30, 10));
	}

	void update_balance(const double newBal)
	{
		_balance += newBal;

		std::ostringstream ostr;
		ostr << "Your Balance\n";
		ostr << std::fixed << std::setprecision(2) << _balance;
		_text.setString(ostr.str() + "$");
		
	}

	

	void draw(sf::RenderWindow& window)
	{
		window.draw(_shape);
		window.draw(_text);
	}

	const bool valid_balance(const double wanted) const
	{
		return this->_balance >= wanted;
	}

private:

	sf::RectangleShape _shape;
	sf::Text _text;
	sf::Font _font;
	double _balance = 100;

};