#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>

#include"BaseText.h"


class Balance : public BaseText
{
public:
	Balance() = delete;

	virtual ~Balance() = default;

	Balance(const sf::Vector2f& position, const sf::Vector2f& size, double balance) :
	BaseText(position,size) , _balance(balance)	
	{
		set_text();
	}

	void update_balance(const double newBal)
	{
		_balance += newBal;
		set_text();
	}

	void draw(sf::RenderWindow& window) final override
	{
		BaseText::draw(window);
	}

	inline const bool check_for_balance(const double wanted) const
	{
		return this->_balance >= wanted;
	}

private:
	double _balance = 100;

	void set_text()
	{
		std::ostringstream ostr;
		ostr << "Your Balance\n";
		ostr << std::fixed << std::setprecision(2) << _balance;
		_text.setString(ostr.str() + "$");
	}

};