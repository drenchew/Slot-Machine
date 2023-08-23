#include "Reel.h"
#include<iostream>

Reel::Reel(const float x, const float y) : bell(BELL), seven(SEVEN), cherry(CHERRY), watermelon(WATERMELON), _x(x), _y(y)
{
    populate();
}


void Reel::populate()
{
    if (!_reel.empty())
    {
        _reel.clear();
    }
    _reel.reserve(8);

    for (int i = 0; i < 8; ++i)
    {
        SymbolType generated_symbol = static_cast<SymbolType>(rand() % 4);

        switch (generated_symbol)
        {
        case BELL: _reel.push_back(bell); break;
        case SEVEN: _reel.push_back(seven); break;
        case WATERMELON: _reel.push_back(watermelon); break;
        case CHERRY: _reel.push_back(cherry); break;
        }
    }

    positionate();
}

void Reel::positionate()
{
    float temp_y = _y;
    for (auto& reel : _reel)
    {
        reel.scale(0.8, 0.8);
        reel.set_position(_x, temp_y);
        temp_y += 80;
    }
}

void Reel::setSpinning(bool spinning) {
    _isSpinning = spinning;
}

bool Reel::isSpinning() const {
    return _isSpinning;
}


void Reel::drawSymbols(sf::RenderWindow& window) {
    for (const auto& symbol : _reel) {

        if (symbol.get_position().y > 80 && symbol.get_position().y < 370)
        {
            symbol.draw(window); // Draw the symbol using its draw method
        }

    }
}


void Reel::updateAnimation() {
    if (_isSpinning) {
        for (auto& symbol : _reel) {

            float temp_y = symbol.get_position().y;
            temp_y += 10; // Adjust this value for the spinning speed                              // 10 defaut
            if (temp_y > 576 + 80) {
                temp_y = -80; // Wrap around if symbols move off the screen
            }
            symbol.set_position(_x, temp_y);
        }
    }
}

void Reel::calculateFinalPosition() {
    if (_isSpinning) {
        this->populate();
        
    }
}