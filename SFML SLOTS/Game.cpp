#include <iostream>
#include <ctime>
#include <cstdlib>
#include"Game.h"

static const sf::Vector2f PlayerPosition(850, 500);
static const sf::Vector2f PlayerSize(110, 40);
static constexpr int InitialBalance = 100;
static constexpr int ReelSpinDuration = 500;
static constexpr int MaxSpinDuration = 2501;

Game::Game() : window(sf::VideoMode(1024, 576), "Bandoleros Slot Machine"), actions() {
}

void Game::StartGame() {
    // Initialize objects and variables

    srand(static_cast<unsigned int>(time(0)));

    Balance player(PlayerPosition, PlayerSize, InitialBalance);
    Symbol background(BACKGROUND);
    background.set_position(0, 0);
    Symbol logo(LOGO);
    logo.set_position(290.0f, 10.0f);


    std::vector<std::shared_ptr<Button>> buttons; // buttons for the bets
    buttons = get_buttons(buttons);
    Action actions;

    std::vector<std::shared_ptr<Reel>> reels; // rows of the slot machine
    reels = get_reels(reels);

    bool StartSpin = true; // Track if the spin button is pressed

    while (window.isOpen()) { //Main Loop
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (const auto& btn : buttons) {
                    if (btn->isMouseOver(window) && StartSpin) {
                        StartSpin = false;
                        SpinRow(reels, actions);
                        actions.timer.restart();
                    }
                }
            }
        }
        UpdateReelAnimations(reels, actions, StartSpin);
        window.clear();
        RefreshResult(reels, logo, buttons, background, player);
    }
}

void Game::SpinRow(std::vector<std::shared_ptr<Reel>>& reels, Action& actions) {
    for (auto& reel : reels) {
        reel->setSpinning(true);
    }
    actions.stopRequested = true;
}

void Game::UpdateReelAnimations(std::vector<std::shared_ptr<Reel>>& reels, Action& actions, bool& StartSpin) {
    for (int i = 0; i < reels.size(); ++i) {
        reels[i]->updateAnimation();
        if (actions.stopRequested == true && actions.timer.getElapsedTime().asMilliseconds() >= (i + 1) * ReelSpinDuration) {
            reels[i]->calculateFinalPosition();
            reels[i]->setSpinning(false);
        }
    }
    if (actions.timer.getElapsedTime().asMilliseconds() > 2501.0f) {
        StartSpin = true;
    }
}

void Game::RefreshResult(std::vector<std::shared_ptr<Reel>>& reels, Symbol& logo, std::vector<std::shared_ptr<Button>>& buttons, Symbol& background, Balance& player) {
    window.clear();
    background.draw(window);
    logo.draw(window);
    player.draw(window);
    for (auto& btn : buttons) {
        btn->draw(window);
    }
    for (auto& reel : reels) {
        reel->drawSymbols(window);
    }
    window.display();
}