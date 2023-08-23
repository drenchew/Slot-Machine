// Inits.cpp
#include "Inits.h"
#include "Button.h"
#include "Reel.h"

std::vector<std::shared_ptr<Button>>& get_buttons(std::vector<std::shared_ptr<Button>>& buttons) {
    std::vector< std::string> bets { "1", "2", "4", "10"};

    float size_x = 110;
    float size_y = 50;

    buttons.emplace_back(std::make_shared<Button>(bets[0], sf::Vector2f(75, 510), sf::Vector2f(size_x, size_y))); // bet for  1 unit

    buttons.emplace_back(std::make_shared<Button>("  " + bets[1], sf::Vector2f(60 + SHIFT + SHIFT / 2, 510), sf::Vector2f(size_x, size_y))); // bet for 2 units

    buttons.emplace_back(std::make_shared<Button>("  " + bets[2], sf::Vector2f(57 + 3 * SHIFT, 510), sf::Vector2f(size_x, size_y))); // bet for  4 units 

    buttons.emplace_back(std::make_shared<Button>(bets[3], sf::Vector2f(75 + 4 * SHIFT + SHIFT / 3, 510), sf::Vector2f(size_x, size_y))); // bet fot 3 units

    return buttons;
}

std::vector<std::shared_ptr<Reel>>& get_reels(std::vector<std::shared_ptr<Reel>>& reels) {
    float x = 270; // the x possition on the screen  //     270
    float y = 100;   // the y possition on the screen  //   100
    for (int row = 0; row < 5; ++row)
    {
        reels.emplace_back(std::make_shared<Reel>(x, y));
        x += SHIFT;
    }

    return reels;
}
