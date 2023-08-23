#ifndef BUTONS_H
#define BUTONS_H

#include <SFML/Graphics.hpp>

#include"BaseText.h"

class Button final : public BaseText
{

    sf::RectangleShape _shape;

    std::string _btnTxt;
    double _bet = 0;

public:
    Button(const std::string& buttonText, const sf::Vector2f& position, const sf::Vector2f& size) : 
        BaseText(position,size), _btnTxt(buttonText)
    {
        _shape.setSize(size);
        _shape.setFillColor(sf::Color::Transparent);
        _shape.setPosition(position);
       // _shape.setOutlineColor(sf::Color::Green);
       // _shape.setOutlineThickness(2.0f);
      
        _text.setString(_btnTxt+ '$');
    }

    virtual ~Button() = default;

    void draw(sf::RenderWindow& window) override final
    {
        window.draw(_shape);
        window.draw(_text);
    }

    bool isMouseOver(const sf::RenderWindow& window)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::FloatRect bounds = _shape.getGlobalBounds();
        return bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }

    float get_bet() const { 
        std::string str = this->_text.getString();
        return std::stof(str);}
};


#endif // !BUTONS_H