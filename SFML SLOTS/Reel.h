#ifndef REEL_H
#define REEL_H


#include "Symbol.h"
#include<vector>
#include<iostream>


class Reel {
private:
    std::vector<Symbol> _reel;
    Symbol bell, seven, cherry, watermelon,grape;
    float _x, _y;
    bool _isSpinning = false;
    
    void positionate();

public:
    Reel(const float x, const float y);
    void populate();
    void updateAnimation();
    void calculateFinalPosition();
    void drawSymbols(sf::RenderWindow& window);
    void setSpinning(bool spinning); 
    bool isSpinning() const ; 
    const SymbolType get_symbol_type(const size_t& idx) const;
    const Symbol& operator[](size_t idx)const { return this->_reel[idx]; }

    friend std::ostream& operator<<(std::ostream& ostr, const Reel& reel);
};



#endif // !REEL_H

