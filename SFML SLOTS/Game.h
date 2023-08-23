#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Reel.h"
#include "Symbol.h"
#include "Button.h"
#include "UserBalance.h"
#include "Inits.h"

struct Action {
    Action() : timer() {}
    double CurBet = 0;
    bool stopRequested = true;
    sf::Clock timer;
};

class Game : private Action {
public:
    Game();

    void StartGame();

private:
    Action actions;
    sf::RenderWindow window;

    void SpinRow(std::vector<std::shared_ptr<Reel>>& reels, Action& actions);
    void UpdateReelAnimations(std::vector<std::shared_ptr<Reel>>& reels, Action& actions, bool& StartSpin);
    void RefreshResult(std::vector<std::shared_ptr<Reel>>& reels, Symbol& logo, std::vector<std::shared_ptr<Button>>& buttons, Symbol& background, Balance& player);
};

#endif // !GAME_H
