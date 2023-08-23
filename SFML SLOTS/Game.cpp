#include <iostream>
#include <ctime>
#include <cstdlib>
#include"Game.h"



SlotMachine::SlotMachine() : window(sf::VideoMode(1024, 576), "Bandoleros Slot Machine"), paterns(this) , player(PlayerPosition, PlayerSize, InitialBalance),
    background(BACKGROUND) , logo(LOGO),lastWin(sf::Vector2f(340,405), sf::Vector2f(300,300)), actions()

{
    Init();
}

void SlotMachine::Init()
{
    background.set_position(0, 0);
    logo.set_position(290.0f, 10.0f);
    lastWin.change_size(50);
    lastWin.set_text("Good Luck!");

    buttons = get_buttons(buttons);

    reels = get_reels(reels);
}

void SlotMachine::StartGame() {
   

    srand(static_cast<unsigned int>(time(0)));



    bool StartSpin = true; // Track if the spin button is pressed
    bool checkPaterns = false;

    while (window.isOpen()) { //Main Loop
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for (const auto& btn : buttons) {
                    if (btn->isMouseOver(window) && StartSpin) {
                        actions.CurBet = btn->get_bet();
                        if (!player.check_for_balance(actions.CurBet)) { continue; }
                        StartSpin = false;
                        checkPaterns = true;
                        SpinRow();
                        
                        //paterns.check_patern1(reels,actions.CurBet);
                       
                        actions.timer.restart();
                    }
                }
            }
        }
        UpdateReelAnimations(StartSpin, checkPaterns);
        window.clear();
        RefreshResult();
    }
}

void SlotMachine::SpinRow() {
    for (auto& reel : reels) {
        reel->setSpinning(true);
    }
    actions.stopRequested = true;
    std::cout << "stop rq\n";
}

void SlotMachine::UpdateReelAnimations( bool& StartSpin,bool& checkPaterns) {
    for (int i = 0; i < reels.size(); ++i) {
        reels[i]->updateAnimation();
        if (actions.stopRequested == true && actions.timer.getElapsedTime().asMilliseconds() >= (i + 1) * ReelSpinDuration) {
            reels[i]->calculateFinalPosition();
            

            reels[i]->setSpinning(false);
        }
    }

    if (checkPaterns && actions.timer.getElapsedTime().asMilliseconds() > 2501.0f)
    {
        paterns.check_patern1(reels, actions.CurBet);
        checkPaterns = false;
    }

    if (actions.timer.getElapsedTime().asMilliseconds() > 2501.0f) {
       
             

        StartSpin = true;
    }
   
   
    
   
}

void SlotMachine::RefreshResult() {
    window.clear();
    background.draw(window);
    logo.draw(window);
    player.draw(window);
    lastWin.draw(window);
    for (auto& btn : buttons) {
        btn->draw(window);
    }
    for (auto& reel : reels) {
        reel->drawSymbols(window);
    }
    window.display();
}