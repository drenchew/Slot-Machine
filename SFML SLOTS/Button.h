#include <SFML/Graphics.hpp>

class Button
{
public:
    sf::RectangleShape _shape;
    sf::Text _text;
    sf::Font _font;
    bool _pressed = false;
    double _bet = 0;
    float _cornerRadius = 20.0f;

public:
    Button(const std::string& buttonText, const sf::Vector2f& position, const sf::Vector2f& size)
    {
        _font.loadFromFile(".\\BAUHS93.TTF");

        _shape.setSize(size);
        _shape.setFillColor(sf::Color::Transparent);
        _shape.setPosition(position);
       // _shape.setOutlineColor(sf::Color::Green);
       // _shape.setOutlineThickness(2.0f);

        _text.setFont(_font);
        _text.setString(buttonText + "$");
        _text.setCharacterSize(20);
        _text.setFillColor(sf::Color::Black);
        _text.setPosition(position + sf::Vector2f(30, 10));

        // You can customize other properties like text color, etc.
    }

    void draw(sf::RenderWindow& window)
    {
        // Draw the main rectangle
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
