#include "Symbol.h"

#define __BELL__ ".\\bell.png"
#define __SEVEN__ ".\\seven.png"
#define __CHERRY__ ".\\cherry.png"
#define __WATERMELON__ ".\\watermelon.png"
#define __LOGO__ ".\\Bandoleros.png"
#define __BACKGROUND__ ".\\back.png"

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
    case LOGO: _symbolTexture.loadFromFile(__LOGO__); break;
    case BACKGROUND: _symbolTexture.loadFromFile(__BACKGROUND__); break;
    default: _type = ERROR; break;
    }
    _symbolSprite.setTexture(_symbolTexture);
}

const SymbolType Symbol::get_type() const
{
    return _type;
}

sf::Sprite& Symbol::get_sprite()
{
    return _symbolSprite;
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
