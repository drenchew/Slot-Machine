#include "Symbol.h"

Symbol::Symbol(): _type(ERROR)
{}

Symbol::Symbol(SymbolType type) : _type(type)
{
    switch (_type)
    {
    case BELL: _symbolTexture.loadFromFile(__BELL__); break;
    case SEVEN: _symbolTexture.loadFromFile(__SEVEN__); break;
    case WATERMELON: _symbolTexture.loadFromFile(__WATERMELON__); break;
    case CHERRY: _symbolTexture.loadFromFile(__CHERRY__); break;
    case GRAPE: _symbolTexture.loadFromFile(__GRAPE__); break;
    case LOGO: _symbolTexture.loadFromFile(__LOGO__); break;
    case BACKGROUND: _symbolTexture.loadFromFile(__BACKGROUND__); break;
    default: _type = ERROR; break;
    }
    _symbolSprite.setTexture(_symbolTexture);
}

void Symbol::draw(sf::RenderWindow& window) const { window.draw(this->_symbolSprite); }

const SymbolType Symbol::get_type() const
{
    return _type;
}

void Symbol::set_position(float w, float h)
{
    _symbolSprite.setPosition(w, h);
}

void Symbol::move_position(float w, float h)
{
    _symbolSprite.move(w, h);
}

void Symbol::scale(float a, float b)
{
    _symbolSprite.setScale(a, b);
}

bool Symbol::operator== (const Symbol& other) const
{
    return this->_type == other.get_type();
}

bool Symbol::operator !=(const Symbol& other) const
{
    return !(*this == other);
}

 std::ostream& operator<<(std::ostream& ostr, const Symbol& symbol)
{
       
         switch (symbol.get_type())
         {
         case CHERRY: ostr << "Cherry";
             break;
         case BELL:ostr << "Bell";
             break;
         case WATERMELON:ostr << "Watermelon";
             break;
         case GRAPE:ostr << "Grape";
             break;
         case SEVEN:ostr << "Seven";
             break;
         default:
             ostr << "ERROR";
             break;
         }
    
         return ostr;
}
